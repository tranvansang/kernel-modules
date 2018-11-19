#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/gfp.h>
#include <linux/delay.h>
#include <linux/sched/task.h>
/*#include <stdlib.h>*/
/*#include <unistd.h>*/
/*#include <sys/types.h>*/
/*#include <sys/wait.h>*/

#define PRINT_PREF "[PROCESS] "

static int __init my_mod_init(void){
  int wstatus = -42;
  int ret = -1;
  pid_t pid = -42;

  printk(PRINT_PREF "Entering module.\n");

  printk(PRINT_PREF "parent: start fork\n");
  pid = _do_fork(
      SIGCHLD,
      0,
      0,
      NULL,
      NULL,
      0
      );

  switch(pid)
  {
    case -1:
    printk(PRINT_PREF "fork error");
      return -1;
    case 0:
      msleep(1000);
      printk(PRINT_PREF "Child process after 1 sec sleep\n");
      return -1;
    default:
      printk(PRINT_PREF "Parent process\n");
      break;
  }
  ret = kernel_wait4(pid, &wstatus, 0, NULL);
  if(ret == -1)
  {
    printk(PRINT_PREF "waitpid error");
    return -1;
  }
  printk(PRINT_PREF "Child exit status: %d\n", wstatus);
  return 0;
}

static void __exit my_mod_exit(void){
  printk(PRINT_PREF "Exiting module.\n");
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
