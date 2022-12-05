##
## ATOS PROJECT 2022
## MAKEFILE
## File description:
## Wow, such make, much file!
##

include ./Makefile.inc

PLUGIN_TYPE = task
PLUGIN_NAME = demeter
PLUGIN_FILE = $(PLUGIN_TYPE)_$(PLUGIN_NAME).so

SRC_FILES = src/demeter_task.c		\
			src/is_writable_path.c	\
			src/get_task_info.c		\

CC		= gcc
CFLAGS	?= -std=gnu11 -Wall -fPIC -Iinclude -I$(SLURM_INC_DIR) -I$(DEMETER_LIB_DIR)/include -Wl,-rpath=$(DEMETER_RUN_PATH)
LDFLAGS	?= -shared -L. -L$(DEMETER_LIB_DIR) -ldemeter

all:	$(PLUGIN_FILE)

default:	$(PLUGIN_FILE)

$(PLUGIN_FILE):	$(SRC_FILES)
		$(CC) $(LDFLAGS) $(CFLAGS) $^ -o $@

send:	all
		scp $(PLUGIN_FILE) my_vm:/home/compose_fake_taranis/plugin/

clean:
		rm -f $(PLUGIN_FILE)

re:	clean all
