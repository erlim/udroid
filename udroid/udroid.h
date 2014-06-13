#ifndef _UDROID_IO_LOG_H_
#define _UDROID_IO_LOG_H_

//buffer type
//#define POLL_ERR 8 
#define ALL_LOG 1
#define IO_LOG 2
#define FILELS_LOG 4

//-->IO Trace 
//io buffer
#define IO_BUF_COUNT 3
#define IO_BUF_SIZE_SHIFT  18
#define IO_BUF_SIZE 1 << IO_BUF_SIZE_SHIFT //0.25mb
//io disk file 
#define IO_FILE_SIZE_SHIFT 20 /* 1024* 1024 */  
#define IO_FILE_SIZE  1 << IO_FILE_SIZE_SHIFT //1mb

//-->FIle life-span
//file life-span buffer
#define FILELS_BUF_COUNT 3
#define FILELS_BUF_SIZE_SHIFT 16  
#define FILELS_BUF_SIZE 1 << FILELS_BUF_SIZE_SHIFT //63336b
//file life-span disk file
#define FILELS_FILE_SIZE_SHIFT 18
#define FILELS_FILE_SIZE 1 << FILELS_FILE_SIZE_SHIFT //0.25mb

//-->data information
//date
#define YEAR_BASE 2000
#define YEAR_RELEASE 14
//ext
#define SQLITE_FILE 0
#define SQLITE_JOURNAL_FILE 1
#define SQLITE_WAL_FILE 2
#define SQLITE_SHM_FILE 3
#define SQLITE_MJ_FILE 4
#define MULTI_FILE 5
#define EXEC_FILE 6
#define RESOURCE_FILE 7
#define ETC_FILE 8
#define UDROID_IO_FILE 9
#define UDROID_FILELS_FILE 10
#define UDROID_MEM_FILE 11
#define UDROID_MEMDETAIL_FILE 12
#define NULL_FILE 15

//rwbs(read,write, synchronous)
#define READ_NONE_MODE 0
#define WRITE_NONE_MODE 1
#define READ_SYNC_MODE 2
#define WRITE_SYNC_MODE 3
//process name
#define PNAME_MAX 16

//struct (cbuf, uio, ufls)
struct cbuf
{
	int id;
	bool full;
	char *data;
	int offset;
	struct cbuf *next;
};

#pragma pack(push,1)
struct uio
{
	//140509 modify ryoung, time(8byte) ->bit(4byte)
	//{ day & time
	unsigned int year:4;  //14,15
	unsigned int month:4;
	unsigned int day:5;
 	unsigned int hour:5;
	unsigned int min:6;
	unsigned int sec:6;
	unsigned int reserved:2; 
	//}
	unsigned int nsec; //nano seconds
	//{ 140428 modify ryoung (fsync, fdatasync)
	unsigned char ext :4;
	unsigned char rwbs :2;
	unsigned char fsync :1;
	unsigned char fdatasync :1;
	//}
	//20140523 add ryoung major,minor device number
	unsigned char major_dev;
	unsigned char minor_dev;
	unsigned int sector_nb; 
	unsigned int block_len; 
	//unsigned int pid;
	unsigned char pname_len;
	//char* pname 
	//unsigned char fname_len;
	//char* fname;
};

struct ufilels
{
	//{ create day&time
	unsigned int c_year:4;
	unsigned int c_month:4;
	unsigned int c_day:5;
	unsigned int c_hour:5;
	unsigned int c_min:6;
	unsigned int c_sec:6;
	unsigned int c_reserved:2;
	unsigned int c_nsec;
	//}
	//{ delete  day&time
	unsigned int d_year:4;
	unsigned int d_month:4;
	unsigned int d_day:5;
	unsigned int d_hour:5;
	unsigned int d_min:6;
	unsigned int d_sec:6;
	unsigned int d_reserved:2;
	unsigned int d_nsec;
	//}
	//{  diff day & time
	unsigned int di_year:4;
	unsigned int di_month:4;
	unsigned int di_day:5;
	unsigned int di_hour:5;
	unsigned int di_min:6;
	unsigned int di_sec:6;
	unsigned int di_reserved:2;
	unsigned int di_nsec;
	//}
	unsigned char ext :4;
	unsigned char reserved :4;
	unsigned char major_dev;
	unsigned char minor_dev;
	long long filesize;
	unsigned char pname_len;
	//char* pname 
	//unsigned char fname_len;
	//char* fname;

	//char* filename; //dynamic size
};
#pragma pack(pop)

#endif
