# include <linux/init.h>
# include <linux/kernel.h>
# include <linux/module.h>

# include <linux/sched.h>
# include <linux/list.h>

int _init_mod (void)
{
   
    struct task_struct *task;
printk(KERN_INFO "Loading module\n");

    printk(KERN_INFO "Gjendja\tID\tEmri\n");
    for_each_process (task)
    { 

        printk(KERN_INFO "%ld \t %d \t %s \n",
            task->state,
            task->pid,
            task->comm
        );
    }

    return 0;
}

void
_exit_mod (void)
{
    printk(KERN_INFO " Removing module\n");
}

module_init (_init_mod);
module_exit (_exit_mod);

MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("Task List");
MODULE_AUTHOR ("Aldo");
