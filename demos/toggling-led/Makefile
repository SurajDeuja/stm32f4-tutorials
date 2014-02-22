PROJ_NAME=main

PROJROOT= ..
SRCS = src/main.c src/system_stm32f4xx.c src/startup_stm32f4xx.s

CC=arm-none-eabi-gcc
GDB=arm-none-eabi-gdb

OBJCOPY=arm-none-eabi-objcopy

OBJDIR = build

CFLAGS  = -g -Wall -Wno-missing-braces -std=c99
CFLAGS += -mthumb -mcpu=cortex-m4
CFLAGS += -mfloat-abi=soft
LDFLAGS = -Wl,-Map,$(OBJDIR)/$(PROJ_NAME).map -g -T$(PROJROOT)/stm32f4_flash.ld


CFLAGS += -Isrc \
	  -I. \
          -I$(PROJROOT)/libraries/STM32F4xx_StdPeriph_Driver/inc \
	  -I$(PROJROOT)/libraries/CMSIS/ST/STM32F4xx/Include \
          -I$(PROJROOT)/libraries/CMSIS/Include

OBJS := $(SRCS:.c=.o)
OBJS := $(OBJS:.s=.o)
OBJS := $(addprefix $(OBJDIR)/,$(OBJS))

all: $(OBJDIR)/$(PROJ_NAME).elf $(OBJDIR)/$(PROJ_NAME).hex $(OBJDIR)/$(PROJ_NAME).bin

$(OBJDIR)/%.elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.hex: %.elf
	$(OBJCOPY) -O ihex $^ $@

%.bin: %.elf
	$(OBJCOPY) -O binary $^ $@

$(OBJDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $^

$(OBJDIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(OBJDIR)/$(PROJ_NAME).elf
	rm -f $(OBJDIR)/$(PROJ_NAME).hex
	rm -f $(OBJDIR)/$(PROJ_NAME).bin
	rm -f $(OBJDIR)/$(PROJ_NAME).map
	find $(OBJDIR) -type f -name '*.o' -print0 | xargs -0 -r rm

# Dependdencies
#$(OBJDIR)/$(PROJ_NAME).elf: $(OBJS) | $(OBJDIR)
