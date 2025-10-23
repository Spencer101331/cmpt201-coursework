thread: thread.c
	clang -pthread $^ -o $@ -fsanitize=address

clean_thread:
	rm -f thread


race: race.c
	clang -pthread $^ -o $@ -fsanitize=address

clean_race:
	rm -f race
