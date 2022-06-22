#include <dlfcn.h>
#include <stddef.h>

// todo: make access to the following global variables restrict to this file
// (I think a static keyword does the job).
// todo: cover the other memory allocation functions (calloc, realloc, etc)
int		malloc_must_fail = 0;
int		nth_malloc_call_to_fail = -1;
int		malloc_call_cnt = 0;
int		alloc_cnt = 0;
int		free_cnt = 0;
void	*(*system_malloc)(size_t) = NULL;
void    (*system_free)(void *) = NULL;

void	simulate_malloc_failure(void)
{
	malloc_must_fail = 1;
}

void	simulate_malloc_failure_on_nth_call(int n)
{
	nth_malloc_call_to_fail = n;
}

void	restore_malloc(void)
{
	malloc_must_fail = 0;
	nth_malloc_call_to_fail = -1;
}

void	reset_malloc_call_cnt(void)
{
	malloc_call_cnt = 0;
}

void	reset_memory_cnt(void)
{
	alloc_cnt = 0;
	free_cnt = 0;
}

int	all_allocations_were_freed(void)
{
	return (alloc_cnt == free_cnt);
}

void	reset_malloc(void)
{
	restore_malloc();
	reset_malloc_call_cnt();
	reset_memory_cnt();
}

void	*malloc(size_t size)
{
	malloc_call_cnt++;
	if (malloc_must_fail
		|| (nth_malloc_call_to_fail > 0 && malloc_call_cnt == nth_malloc_call_to_fail))
		return (NULL);
	if (system_malloc == NULL)
		system_malloc = dlsym(RTLD_NEXT, "malloc");
	alloc_cnt++;
	// todo: handle actual nomem error
	return system_malloc(size);
}

void    free(void *s)
{
	if (system_free == NULL)
		system_free = dlsym(RTLD_NEXT, "free");
	free_cnt++;
	system_free(s);
}
