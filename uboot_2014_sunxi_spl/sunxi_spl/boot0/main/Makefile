
##
## Makefile for Sunxi Secure Boot
##


include $(SPLDIR)/config.mk

LIB	:= $(obj)libmain.o
LIB_NOR	:= $(obj)libmain_nor.o
LIB_MMC	:= $(obj)libmain_mmc.o

HEAD    := boot0_head.o

DATA    := boot0_hash.o
START	:= boot0_entry.o
COBJS   += boot0_main.o
COBJS_NOR := boot0_main_nor.o

SRCS	:= $(START:.o=.S) $(COBJS:.o=.c) $(HEAD:.o=.c)
OBJS	:= $(addprefix $(obj),$(COBJS) $(COBJS-y) $(SOBJS))
OBJS_NOR:= $(addprefix $(obj),$(COBJS_NOR))
HEAD    := $(addprefix $(obj),$(HEAD))
START	:= $(addprefix $(obj),$(START))


all:	$(obj).depend $(HEAD) $(START) $(LIB) $(DATA) $(LIB_NOR) $(LIB_MMC)

#this boot0_main funtition for NAND
$(LIB):	$(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#this boot0_main function for MMC flash
$(LIB_MMC): $(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#this for SPINOR macro so that you can use CONFIG_BOOT0_NOR to differentiate /
# NAND and EMMC in boot0_main.c
$(COBJS_NOR): boot0_main.c
	@$(CC)  $(ALL_CFLAGS) -o $@ $< -c -D CONFIG_BOOT0_NOR
	@echo " CC      "$< ...

$(LIB_NOR): $(COBJS_NOR)
	$(call cmd_link_o_target, $(COBJS_NOR))



#########################################################################

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
