#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "udroid.h"

static char input_file[100];
static char output_file[100];

static int io_parser()
{
	FILE *read_file, *parse_file;
	struct uio log;
	int log_size;
	char pname[16];
	int fname_len;
	char fname[100];
	char s_log[200];
	
	log_size = 0;
	memset(pname, 0, 16);
	memset(fname,0,100);
	memset(s_log,0,200);

	read_file = fopen(input_file, "rb");
	if(read_file == NULL){
		printf("failed to open original binary file\n");
		return -1;
	}
	parse_file = fopen(output_file, "aw");
	if(parse_file == NULL){
		printf("failed to open parse_file\n");
		return -1;
	}
	while(!feof(read_file)){
		memset(s_log,0,200);
		memset(pname, 0, 16);
		fread(&log_size, 1,1,read_file);
		fread(&log, sizeof(struct uio), 1, read_file);
		fread(pname, log.pname_len, 1, read_file);
		fread(&fname_len, 1, 1, read_file);
		fread(fname, fname_len, 1, read_file);
	
		sprintf(s_log, "%d%d%d%d%d%d %d\t ext:%d\t rwbs:%d\t  fsync:%d %d\t device:%d %d\t sector_nb:%d %d\t %s\t %s\n", 
				log.year,log.month,log.day,log.hour,log.min,log.sec, log.nsec,
				log.ext, log.rwbs, log.fsync, log.fdatasync, 
				log.major_dev, log.minor_dev, log.sector_nb, log.block_len, 
				pname, fname);

		printf("%s\n", s_log);
		fwrite(s_log, 1, strlen(s_log), parse_file);
	}
	
	return 0;
}

static int filels_parser()
{
	FILE *read_file, *parse_file;
	struct ufilels log;
	int log_size;
	char pname[16];
	int fname_len;
	char fname[100];
	char s_log[200];

	
	log_size = 0;
	memset(pname,0,16);
	memset(fname,0, 100);
	memset(s_log,0,100);

	read_file = fopen(input_file, "rb");
	if(read_file == NULL){
		printf("failed to open original binary file\n");
		return -1;
	}
	
	parse_file = fopen(output_file, "aw");
	if(parse_file == NULL){
		printf("failed to open parse_file\n");
		return -1;
	}
	while(!feof(read_file)){
		memset(s_log,0,200);
		memset(pname, 0, 16);
		memset(fname, 0 ,100);
		fread(&log_size, 1,1,read_file);
		fread(&log, sizeof(struct ufilels), 1, read_file);
		fread(pname, log.pname_len, 1, read_file);
		fread(&fname_len, 1, 1, read_file);
		fread(fname, fname_len, 1, read_file);
		
		sprintf(s_log, "%d%d%d%d%d%d %d\t %d%d%d%d%d%d %d\t %d%d%d%d%d%d %d\t %d\t %lld\t %s\t %s\n", 
			log.c_year, log.c_month, log.c_day, log.c_hour, log.c_min, log.c_sec, log.c_nsec,
			log.d_year, log.d_month, log.d_day, log.d_hour, log.d_min, log.d_sec, log.d_nsec,
			log.di_year, log.di_month, log.di_day, log.di_hour, log.di_min, log.di_sec, log.di_nsec,
			log.ext, log.filesize, pname, fname);

		printf("%s\n", s_log);
		//fwrite(log, 1, strlen(s_log), parse_file);
	}

	return 0;
}

int main(int argc, char **argv)
{
	char temp[20]; 
	int slen =0;
	memset(temp,0,20);

	printf("input file path\n");
	scanf("%s", temp);

	sprintf(input_file, "/home/ryoung/src/nexus5/log/%s", temp);
	sprintf(output_file, "/home/ryoung/src/nexus5/log/%s_parse.txt", temp);
	slen = strlen(input_file);

	if(input_file[slen-4] == '.' && input_file[slen-3] == 'u' && input_file[slen-2] =='i' && input_file[slen-1] == 'o'){
		io_parser();
	}else if(input_file[slen-5] == '.' && input_file[slen-4] == 'u' && input_file[slen-3] == 'f' && input_file[slen-2] == 'l' &&  input_file[slen-1] == 's'){
		filels_parser();
	}

	return true;
}

