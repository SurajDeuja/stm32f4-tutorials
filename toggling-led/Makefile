PROJ_NAME=main

STD_PERIPH=..

SRCS = main.c system_stm32f4xx.c startup_stm32f4xx.s

CC=arm-none-eabi-gcc
GDB=arm-none-eabi-gdb

OBJCOPY=arm-none-eabi-objcopy

OBJDIR = build

CFLAGS  = -g3 -Wall -Wno-missing-braces -std=c99
CFLAGS += -mthumb -mcpu=cortex-m4
CFLAGS += -mfloat-abi=soft
LDFLAGS = -Wl,-Map,$(OBJDIR)/$(PROJ_NAME).map -g -T$(STD_PERIPH)/stm32f4_flash.ld

CFLAGS += -I. \
          -I$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/inc \
	  -I$(STD_PERIPH)/libraries/CMSIS/ST/STM32F4xx/Include \
          -I$(STD_PERIPH)/libraries/CMSIS/Include

SRCS += $(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.c       \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.c   \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.c       \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.c       \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.c   \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.c  \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/misc.c                 \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.c       \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.c       \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.c       \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.c      \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.c   \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c       \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.c  \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.c       \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.c      \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.c       \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.c     \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.c     \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.c        \
	$(STD_PERIPH)/libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.c
#	libraries/CMSIS/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c\

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

clean:
	rm -rf build
	rm -rf libraries
	#rm -f $(OBJDIR)/$(PROJ_NAME).elf
	#rm -f $(OBJDIR)/$(PROJ_NAME).hex
	#rm -f $(OBJDIR)/$(PROJ_NAME).bin
	#rm -f $(OBJDIR)/$(PROJ_NAME).map
	#find $(OBJDIR) -type f -name '*.o' -print0 | xargs -0 -r rm

# Dependdencies
$(OBJDIR)/$(PROJ_NAME).elf: $(OBJS) | $(OBJDIR)

