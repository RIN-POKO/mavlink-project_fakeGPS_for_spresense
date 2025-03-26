# Application makefile

# Command name (Public function 'int <APPNAME>_main(void)' required)
APPNAME = GPS

# Application execute priority (Range: 0 ~ 255, Default: 100)
PRIORITY =

# Application stack memory size (Default: 2048)
STACKSIZE =

# Main source code
MAINSRC = GPS_main.cxx

# Additional C source files (*.c)
CSRCS =

# Additional C++ source files (*.cxx)
CXXSRCS = 

# Additional assembler source files (*.S)
ASRCS =

# C compiler flags
CFLAGS =

# C++ compiler flags
CXXFLAGS =

CXXFLAGS += -D_POSIX
CXXFLAGS += -DUSE_MEMMGR_FENCE
CXXFLAGS += -DATTENTION_USE_FILENAME_LINE

include $(SPRESENSE_HOME)/.vscode/application.mk