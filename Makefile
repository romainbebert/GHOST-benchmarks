all: build_order resource target wallin

build_order:
	(cd build_order && $(MAKE))

resource:
	(cd resource && $(MAKE))

target:
	(cd target && $(MAKE))

wallin:
	(cd wallin && $(MAKE))

