KERNELDIR=/lib/modules/`uname -r`/build

MODULES = lowLevel.ko
obj-m += lowLevel.o

build:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	make -C $(KERNELDIR) M=$(PWD) clean

install:	
	#make -C $(KERNELDIR) M=$(PWD) modules_install
	sudo insmod lowLevel.ko

uninstall:
	sudo rmmod lowLevel

quickInstall:
	#cp $(MODULES) /lib/modules/`uname -r`/extra
