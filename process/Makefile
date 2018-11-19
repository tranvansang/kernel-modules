MOD = process
KERNELDIR=/lib/modules/`uname -r`/build

MODULES = $(MOD).ko
obj-m += $(MOD).o

build:
	make -C $(KERNELDIR) M=$(PWD) modules
	gcc -Wall -Werror process-orginal.c -o process

run:
	./process

trace:
	strace -f ./process > /dev/null

install:	
	#make -C $(KERNELDIR) M=$(PWD) modules_install
	sudo insmod $(MOD).ko

uninstall:
	sudo rmmod $(MOD)

clean:
	rm -rf process
	make -C $(KERNELDIR) M=$(PWD) clean
