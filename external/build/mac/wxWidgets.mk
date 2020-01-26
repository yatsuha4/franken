# wxWidgets-3.1.3

TARGET	:= wxWidgets

include $(dir $(lastword $(MAKEFILE_LIST)))/setting.mk

.PHONY: $(TARGET)
$(TARGET):
	rm -rf $(WORKDIR)
	mkdir -p $(WORKDIR)
	cd $(WORKDIR); \
	$(SRCDIR)/configure \
		--disable-shared \
		--enable-monolithic \
		--with-libpng=builtin \
		--with-libjpeg=builtin \
		--with-libtiff=builtin \
		--prefix=$(OPTDIR) \
		--with-macosx-version-min=$(DEPLOYMENT_TARGET); \
	make; \
	make install
