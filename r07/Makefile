all: mmu mmu_test buffer_overflow questions
	@echo "Done"

mmu: mmu.c mmu_lib.c
	gcc mmu.c mmu_lib.c -o mmu

mmu_test: mmu_test.c mmu_lib.c
	gcc mmu_test.c mmu_lib.c -o mmu_test

questions: questions.c
	gcc questions.c -o questions

buffer_overflow: buffer_overflow.c
	gcc buffer_overflow.c -O0 -fno-stack-protector -o buffer_overflow

clean:
	rm -f mmu mmu_test buffer_overflow questions
