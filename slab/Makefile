MOD = slab
KERNELDIR=/lib/modules/`uname -r`/build

MODULES = $(MOD).ko
obj-m += $(MOD).o

build:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	make -C $(KERNELDIR) M=$(PWD) clean

install:	
	#make -C $(KERNELDIR) M=$(PWD) modules_install
	sudo insmod $(MOD).ko

uninstall:
	sudo rmmod $(MOD)

quickInstall:
	#cp $(MODULES) /lib/modules/`uname -r`/extra
