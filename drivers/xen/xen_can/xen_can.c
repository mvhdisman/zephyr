

#include <arch/arm64/hypercall.h>
#include <xen/console.h>
#include <xen/events.h>
#include <xen/generic.h>
#include <xen/hvm.h>
#include <xen/public/io/console.h>
#include <xen/public/sched.h>
#include <xen/public/xen.h>

#include <device.h>
#include <init.h>
#include <kernel.h>
#include <sys/device_mmio.h>


#include <xen/public/xen.h>
#include <xen/public/event_channel.h>
#include <xen/events.h>

#include <errno.h>
#include <kernel.h>
#include <logging/log.h>


#include <logging/log.h>
LOG_MODULE_REGISTER(xen_can, CONFIG_UART_LOG_LEVEL);

static struct hvc_xen_data hvc_data = {0};



int xen_can_init(const struct device *dev)
{
    int rc = 0;
    printk("\nxen_can init\n");


    rc = evtchn_alloc_unbound(DOMID_SELF, 0);
    printk("evtchn allocated rc: %d\n", rc);


    rc = evtchn_bind_interdomain(0, 29);
    printk("evtch bound rc: %d\n",rc);

    return 0;


}



DEVICE_DT_DEFINE(DT_NODELABEL(xen_can), xen_can_init, NULL, &hvc_data,
		NULL, POST_KERNEL, CONFIG_XEN_HVC_INIT_PRIORITY,
		NULL);
