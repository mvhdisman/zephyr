/* main.c - Hello World demo */

/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

/* Can related */
#include <device.h>

/* Xen related */
#include <xen/gnttab.h>
#include <xen/xenbus/xs.h>
#include <xen/xenbus/xenbus.h>

#include <stdio.h>


#define PIN_THREADS (IS_ENABLED(CONFIG_SMP)		  \
		     && IS_ENABLED(CONFIG_SCHED_CPU_MASK) \
		     && (CONFIG_MP_NUM_CPUS > 1))

/* size of stack area used by each thread */
#define STACKSIZE 1024

/* scheduling priority used by each thread */
#define PRIORITY 7

/* delay between greetings (in ms) */
#define SLEEPTIME 5000



extern void do_write_test(const char *path, const char *val);


struct xenbus_driver *xdrv;

struct xenbus_device xdev;

xenbus_transaction_t xbt;

void main(void)
{
	k_msleep(SLEEPTIME);
	printk("entering main\n");
    

	// int rc = 0;
	// //printk("Doing write test.\n"); 
    // //do_write_test("data/stuff", "flobble");

	// char buf[1024];
	// domid_t domid = xs_get_self_id();
	// if (!domid) {
	// 	printk("Zero domid returned\n");
	// 	return;
	// }
	

	// char *name = {"channel0"};
	// sprintf(buf, "/dummy/%s", name);
	
	// rc = xs_rm(XBT_NIL, buf);
	// k_free(name);
	// if (rc < 0)
	// {
	// 	printk("xs_rm failed. rc=%d",rc);
	// 	return;
	// }

	// rc = xs_write(XBT_NIL, buf, "");
	// if (rc < 0)
	// {
	// 	printk("xs_write failed. rc=%d",rc);
	// 	return;
	// }

	// char perms = XS_PERM_READ | XS_PERM_WRITE;
	// rc = xs_set_perm(XBT_NIL, buf, domid, perms);
	// if (rc < 0)
	// {
	// 	printk("xs_set_perm failed. rc=%d",rc);
	// 	return;
	// }

	// printk("%s: domid returned = %u\n", __func__, domid);

	// snprintf(buf, 50, "/local/domain/%u/hej", domid);

	// printk("%s: running xenbus mkdir for %s\n", __func__, buf);
	// rc = xs_transaction_start(&xbt);
	// if(rc < 0)
	// {
	// 	printk("\ntransaction error\n");
	// }


	// rc = xs_set_perm(xbt, buf, domid, XS_PERM_BOTH);
	// if(rc < 0)
	// {
	// 	printk("\nperm error rc = %d\n",rc);
	// }


	// rc = xs_mkdir(xbt, buf);
	// if(rc < 0)
	// {
	// 	printk("\ndirectory error rc = %d\n",rc);
	// }
	// /* Setup xen driver */




	printk("exiting\n");
	while(1);
}
