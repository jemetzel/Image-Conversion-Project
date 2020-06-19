.PHONY: clean
p3_p6: bytes.h bytes.c p3_p6.c
	clang -Wall -o p3_p6 bytes.c p3_p6.c 
p6_p3: bytes.h bytes.c p6_p3.c
	clang -Wall -o p6_p3 bytes.c p6_p3.c 
p152_ppm: bytes.h bytes.c colors.h colors.c p152_ppm.c
	clang -Wall -o p152_ppm bytes.c colors.c p152_ppm.c 
ppm_p152: bytes.h images.h dates.h colors.h bytes.c images.c dates.c colors.c ppm_p152.c
	clang -Wall -o ppm_p152 bytes.c images.c dates.c colors.c ppm_p152.c
negative: bytes.h images.h bytes.c images.c negative.c
	clang -Wall -o negative negative.c images.c dates.c
describe: bytes.h bytes.c describe.c
	clang -Wall -o describe bytes.c describe.c
clean:
	rm -f p3_p6 p6_p3 p152_ppm ppm_p152 negative describe a.out
