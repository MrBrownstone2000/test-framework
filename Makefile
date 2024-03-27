target = Debug

ifneq ($(target), Debug)
	ifneq ($(target), Release)
	  $(error Wrong target)
	endif
endif

.PHONY: clean build runExample

build:
	@cmake -DCMAKE_BUILD_TYPE=$(target) -DBUILD_EXAMPLE=ON -S . -B build >> /dev/null
	@cmake --build build --target install

clean:
	@rm -rf install build

runExample:
	@build/example/example_tests
