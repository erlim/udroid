#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xd775a2ab, "module_layout" },
	{ 0x3e8a656d, "class_destroy" },
	{ 0xf50ccad8, "device_destroy" },
	{ 0x7eaf0d5, "cdev_del" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x604d887f, "device_create" },
	{ 0x12d12ca4, "cdev_add" },
	{ 0x890d342e, "cdev_init" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xfbd0dc95, "__class_create" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0xbc3d21af, "finish_wait" },
	{ 0x69ff5332, "prepare_to_wait" },
	{ 0x1000e51, "schedule" },
	{ 0x87918a26, "kmalloc_caches" },
	{ 0xa7ecf324, "__init_waitqueue_head" },
	{ 0x86a4889a, "kmalloc_order_trace" },
	{ 0x322c1429, "kmem_cache_alloc_trace" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xaea99e9d, "_raw_spin_unlock_irq" },
	{ 0x37a0cba, "kfree" },
	{ 0xe551272c, "_raw_spin_lock_irq" },
	{ 0x27e1a049, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "21A1A9DA8B420E7D042579D");
