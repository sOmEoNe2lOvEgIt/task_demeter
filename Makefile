##
## ATOS PROJECT 2022
## MAKEFILE
## File description:
## Wow, such make, much file!
##

SLURM_ROOT_DIR = /usr
SLURM_INC_DIR = /root/SLURM/slurm.build
SLURM_LIB_DIR = /usr/lib64/slurm
SLURM_BUILD = 21.08.8-2
SLURM_BUILD_DIR = /root/rpmbuild/BUILD/slurm-$(SLURM_BUILD)

PLUGIN_TYPE = task
PLUGIN_NAME = demeter
PLUGIN_FILE = $(PLUGIN_TYPE)_$(PLUGIN_NAME).so
DEMETER_LIB_DIR = /home/atos_projects/prep_demeter

SRC_FILES = src/demeter_task.c		\
			src/get_conf_path.c		\
			src/is_writable_path.c	\

CC		= gcc
CFLAGS	?= -Wall -fPIC -g -Iinclude -I$(SLURM_INC_DIR) -I$(SLURM_BUILD_DIR)
LDFLAGS	?= --shared -L. -L$(DEMETER_LIB_DIR) -ldemeter

all:	$(PLUGIN_FILE)

default:	$(PLUGIN_FILE)

$(PLUGIN_FILE):	$(SRC_FILES)
		$(CC) $(LDFLAGS) $(CFLAGS) $^ -o $@

send:	all
		scp $(PLUGIN_FILE) my_vm:/home/compose_fake_taranis/plugin/

clean:
		rm -f $(PLUGIN_FILE)

re:	clean all