.PHONY: all shrink clean

CWD := $(shell pwd)
STAGING := $(CWD)/staging

RM := rm -f

all:
	$(MAKE) -C target

shrink:
	$(RM) -r target/build
	$(RM) target/._*

clean: shrink
	${RM} -R ${STAGING}
