#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

MODULE_AUTHOR("WCF");
MODULE_LICENSE("GPL");

static int nbr = 10;
module_param(nbr, int, S_IRUGO);

static int __init hello_init(void)
{
  int i;
  for(i = 0; i < nbr; i++)
  {
    printk(KERN_ALERT "hello, how are you.%d\n",i);
  }
  return 0;
}

static void __exit hello_exit(void)
{
  printk(KERN_ALERT "i come from hello's module,I have benn unload.\n");
}

module_init(hello_init);
module_exit(hello_exit);
