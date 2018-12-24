.PHONY: all mrproper clean

CWD := $(shell pwd)
BUILD := $(CWD)/build
STAGING := $(CWD)/staging
SOURCES := /home/knightwu/software/thirdparty/sources

MKDIR := mkdir -p
CMAKE := cmake
CP := cp -af
RM := rm -f
LN := ln -f

define M
._$(1): $(foreach D,$(3),._$(D))
	@echo $(1)
	$(RM) -R $(BUILD)/$$(basename $$(basename $2))
	$(MKDIR) $(BUILD) && cd $(BUILD) && tar -xaf $(SOURCES)/$2
	cd $(BUILD)/$$(basename $$(basename $2)) && \
		./configure --prefix=$$(STAGING) $(4) && $$(MAKE) $(5) && $$(MAKE) $(6) install
endef

all: mrproper \
	.httpd

mrproper:

clean:
	${RM} -R ${BUILD}
	${RM} -R ${STAGING}

.httpd: ._apr
#	._apr-util ._pcre ._openssl ._libxml2 ._nghttp2


$(eval $(call M,apr,apr-1.6.3.tar.bz2,util-linux,--enable-threads --enable-posix-shm))
$(eval $(call M,util-linux,util-linux-2.21.2.tar.xz,,--without-ncurses --disable-nls,-C libuuid,-C libuuid))
