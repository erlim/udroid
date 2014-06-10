obj-m := ../udroid.o
	     
KDIR := /home/ryoung/src/nexus5/msm
CCPATH := /home/ryoung/src/nexus5/arm-eabi-4.6-master/bin
default:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(CCPATH)/arm-eabi- -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean

