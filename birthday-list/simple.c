#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

/* PERCAKTOJME STRUKTUREN E DATELINDJES. */

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
};

/* Krijohet objekti LIST_HEAD, qe perdoret si reference per koken e listes. */

static LIST_HEAD(birthday_list);

int simple_init(void) {

/* Krijohen dhe inicializohen instancat e struktures birthday. */

  struct birthday *people[5];
  struct birthday *ptr;

/* Shtohen elementet. */

  people[0] = kmalloc(sizeof(struct birthday), GFP_KERNEL);
  people[0]->day = 16;
  people[0]->month = 6;
  people[0]->year = 1995;
  INIT_LIST_HEAD(&people[0]->list);
  list_add_tail(&people[0]->list, &birthday_list);

  people[1] = kmalloc(sizeof(struct birthday), GFP_KERNEL);
  people[1]->day = 27;
  people[1]->month = 7;
  people[1]->year = 1990;
  INIT_LIST_HEAD(&people[1]->list);
  list_add_tail(&people[1]->list, &birthday_list);

  people[2] = kmalloc(sizeof(struct birthday), GFP_KERNEL);
  people[2]->day = 3;
  people[2]->month = 4;
  people[2]->year = 1990;
  INIT_LIST_HEAD(&people[2]->list);
  list_add_tail(&people[2]->list, &birthday_list);

  people[3] = kmalloc(sizeof(struct birthday), GFP_KERNEL);
  people[3]->day = 9;
  people[3]->month = 12;
  people[3]->year = 1994;
  INIT_LIST_HEAD(&people[3]->list);
  list_add_tail(&people[3]->list, &birthday_list);

  people[4] = kmalloc(sizeof(struct birthday), GFP_KERNEL);
  people[4]->day = 5;
  people[4]->month = 5;
  people[4]->year = 1995;
  INIT_LIST_HEAD(&people[4]->list);
  list_add_tail(&people[4]->list, &birthday_list);

  printk(KERN_INFO "Loading Module\n");

/* Bridhet lista dhe afishohen elementet e shtuar. */

  list_for_each_entry(ptr, &birthday_list, list) {
    printk(KERN_INFO "%d/%d/%d\n", ptr->day, ptr->month, ptr->year);
  }

  return 0;
}

void simple_exit(void) {
  struct birthday *ptr, *next;

  printk(KERN_INFO "Removing Module\n");

/* Bridhet lista dhe afishohen elementet para heqjes. */

  list_for_each_entry_safe(ptr, next, &birthday_list, list) {
    printk(KERN_INFO "Deleting %d/%d/%d\n", ptr->day, ptr->month, ptr->year);
    list_del(&ptr->list);
    kfree(ptr);
  }
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Lista Modulit");
MODULE_AUTHOR("Aldo");


