<h1 align="center">libft</h1>

<blockquote>This project is about coding a C library. It will contain a lot of general purpose functions your programs will rely upon.</blockquote>

<h2 align="center">
  <a href="#libc-functions">Libc functions</a>
  ·
  <a href="#additional-functions">Additional functions</a>
  ·
  <a href="#bonus-functions">Bonus functions</a>
</h2>

<h2 align="center">:white_check_mark: Everything passes francinette and francinette strict. :white_check_mark:</h2>

<div align="center">
  <img src="https://github.com/aflr/aflr/blob/main/src/badges/libftm.png">
</div>

<h2>Libc functions</h2>
<table>
  <tr>
    <th>Function name</th>
    <th>Original C library</th>
    <th>Description</th>
    <th>Go to code explanation</th>
    <th>Link to source code</th>
  </tr>
  <tr>
    <td>ft_isalpha</td>
    <td>&lt;ctype.h&gt;</td>
    <td>Checks if the given character is an alphabetic character, i.e. either an uppercase or lowercase letter.</td>
    <td><a href="#ft_isalpha">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_isalpha.c">ft_isalpha.c</a></td>
  </tr>
  <tr>
    <td>ft_isdigit</td>
    <td>&lt;ctype.h&gt;</td>
    <td>Checks for a digit (0 through 9).</td>
    <td><a href="#ft_isdigit">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_isdigit.c">ft_isdigit.c</a></td>
  </tr>
</table>

<h2>Additional functions</h2>
<table>
  <tr>
    <th>Function name</th>
    <th>Description</th>
    <th>Go to code explanation</th>
    <th>Link to source code</th>
  </tr>
  <tr>
    <td>ft_substr</td>
    <td>Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.</td>
    <td><a href="#ft_substr">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_substr.c">ft_substr.c</a></td>
  </tr>
  <tr>
    <td>ft_strjoin</td>
    <td>Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.</td>
    <td><a href="#ft_strjoin">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_strjoin.c">ft_strjoin.c</a></td>
  </tr>
  <tr>
    <td>ft_strtrim</td>
    <td>Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
</td>
    <td><a href="#ft_strtrim">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_strtrim.c">ft_strtrim.c</a></td>
  </tr>
  <tr>
    <td>ft_split</td>
    <td>Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must end with a NULL pointer.</td>
    <td><a href="#ft_split">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_split.c">ft_split.c</a></td>
  </tr>
  <tr>
    <td>ft_itoa</td>
    <td>Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.</td>
    <td><a href="#ft_itoa">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_itoa.c">ft_itoa.c</a></td>
  </tr>
  <tr>
    <td>ft_strmapi</td>
    <td>Applies the function ’f’ to each character of the string ’s’, and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.</td>
    <td><a href="#ft_strmapi">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_strmapi.c">ft_strmapi.c</a></td>
  </tr>
  <tr>
    <td>ft_striteri</td>
    <td>Applies the function ’f’ on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to ’f’ to be modified if necessary.</td>
    <td><a href="#ft_striteri">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_striteri.c">ft_striteri.c</a></td>
  </tr>
  <tr>
    <td>ft_putchar_fd</td>
    <td>Outputs the character ’c’ to the given file descriptor.</td>
    <td><a href="#ft_putchar_fd">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_putchar_fd.c">ft_putchar_fd.c</a></td>
  </tr>
  <tr>
    <td>ft_putstr_fd</td>
    <td>Outputs the string ’s’ to the given file descriptor.</td>
    <td><a href="#ft_putstr_fd">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_putstr_fd.c">ft_putstr_fd.c</a></td>
  </tr>
  <tr>
    <td>ft_putendl_fd</td>
    <td>Outputs the string ’s’ to the given file descriptor followed by a newline.</td>
    <td><a href="#ft_putendl_fd">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_putendl_fd.c">ft_putendl_fd.c</a></td>
  </tr>
  <tr>
    <td>ft_putnbr_fd</td>
    <td>Outputs the integer ’n’ to the given file descriptor.</td>
    <td><a href="#ft_putnbr_fd">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_putnbr_fd.c">ft_putnbr_fd.c</a></td>
  </tr>
</table>

<h2>Bonus functions</h2>
<table>
  <tr>
    <th>Function name</th>
    <th>Description</th>
    <th>Go to code explanation</th>
    <th>Link to source code</th>
  </tr>
  <tr>
    <td>ft_lstnew</td>
    <td>Allocates (with malloc(3)) and returns a new node. The member variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.</td>
    <td><a href="#ft_lstnew">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_lstnew_bonus.c">ft_lstnew_bonus.c</a></td>
  </tr>
  <tr>
    <td>ft_lstadd_front</td>
    <td>Adds the node ’new’ at the beginning of the list.</td>
    <td><a href="#ft_lstadd_front">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_lstadd_front_bonus.c">ft_lstadd_front_bonus.c</a></td>
  </tr>
  <tr>
    <td>ft_lstsize</td>
    <td>Counts the number of nodes in a list.</td>
    <td><a href="#ft_lstsize">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_lstsize_bonus.c">ft_lstsize_bonus.c</a></td>
  </tr>
  <tr>
    <td>ft_lstlast</td>
    <td>Returns the last node of the list.</td>
    <td><a href="#ft_lstlast">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_lstlast_bonus.c">ft_lstlast_bonus.c</a></td>
  </tr>
  <tr>
    <td>ft_lstadd_back</td>
    <td>Adds the node ’new’ at the end of the list.</td>
    <td><a href="#ft_lstadd_back">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_lstadd_back_bonus.c">ft_lstadd_back_bonus.c</a></td>
  </tr>
</table>

<hr>

<h2>ft_isalpha</h2>

```c
/*
Theory:
All relational (< <= > >= == !=) and logical (&& || !) operations
in C evaluate to a zero (0) when false, or one (1) when true.
Also, all numeric values are considered to be true except zero (0).

This function will return 1 (true) when the character received as
parameter has an ASCII value in the interval:
(c >= 'a' && c <= 'z') which are all the lowercase letters
OR
(c >= 'A' && c <= 'Z') which are all the uppercase letters
*/

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
```

<h2>ft_isdigit</h2>

```c
/*
Theory:
The characters '0' through '9' have ASCII values 48 through 57.

This function will return 1 (true) when the character received as
parameter has an ASCII value between '0' and '9'.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
```

<hr>

<h2>ft_substr</h2>

```c
/*
This function, ft_min, is an auxiliary function used to return the smaller
of two unsigned values. All auxiliary functions must be declared as static,
which limits their scope (places where this function can be called) to this file.
*/
static size_t	ft_min(size_t n1, size_t n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

/*
Parameters
's': The string from which to create the substring
'start': The start index of the substring in the string ’s’
'len': The maximum length of the substring
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	real_len;
	unsigned int	i;

	// Find out the length of the string 's' we are given as parameter
	real_len = ft_strlen(s);
	// If the 'start' index is outside of the parameter string 's',
	// malloc and return empty string. For convenience, we use ft_strdup
	// Example:
	// ft_substr("hello", 200, 5)
	if (start > real_len)
		return (ft_strdup(""));
	// Now that we know 'start' is a valid index inside our string 's',
	// we calculate how much memory space we need.
	// The parameter 'len' tells us the maximum length of the string, but it
	// could be the case that the substring is smaller.
	// Example:
	// ft_substr("hello", 3, 42)
	// Starting from index 3, we get the string "lo". The 'len' being 42 does
	// not matter because the real length of the string from the starting index
	// is smaller. In this case, we would malloc 3 bytes -> (5 - 3) + 1
	substr = malloc(sizeof(char) * (ft_min(len, real_len - start) + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	// Now we copy characters from 's' until:
	// we have already copied 'len' characters
	// OR
	// we reach the end of the string 's'
	// Notice how we don't start copying at index 0, we start at index 'start'
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		++i;
	}
	// All strings in C must end with a null terminator, the character '\0'
	substr[i] = '\0';
	return (substr);
}
```

<h2>ft_strjoin</h2>

```c
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	// We allocate enough memory for 's1' + 's2' + 1 (for the '\0' byte at the end)
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	// We copy 's1' into 'new' starting at 'res' position 0
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		++i;
	}
	// We copy 's2' into 'new' starting at 'res' position 'i'
	// 'i' is the index where we finished copying 's1'
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	// All strings in C must end with a null terminator, the character '\0'
	res[i] = '\0';
	return (res);
}
```

<h2>ft_strtrim</h2>

```c
/*
This auxiliary function puts the indexes of the first and last characters
in the string 's1' which are not part of the string 'set'.
It is useful because 'last' - 'first' + 1 is the length of the resulting string
*/
static void	calculate_valid_range(int *first, int *last,
	char const *s1, char const *set)
{
	int	i;

	*first = -1;
	*last = -1;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
		{
			if (*first == -1)
				*first = i;
			*last = i;
		}
		++i;
	}
}

/*
The function removes all characters from string 'set' found
at the beginning and end of the string 's1'
Example: ft_strtrim("   hello    world    ", " ") -> "hello    world"
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		first_char;
	int		last_char;
	int		len;

	// This function gives me the indexes of the first
	// and last characters that must not be removed
	calculate_valid_range(&first_char, &last_char, s1, set);
	// If all characters in 's1' must be removed, return empty string
	if (first_char == -1)
		return (ft_strdup(""));
	len = last_char - first_char + 1;
	// Malloc the necessary length + 1 (for \0 character)
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	// Copy from 's1' into 'res'. Use 'first_char' as an offset,
	// to skip the removed chars at the beginning of 's1'
	while (i < len)
	{
		res[i] = s1[first_char + i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
```

<h2>ft_split</h2>

```c
/*
Auxiliary function to count how many words are in a string, given
a delimiter character 'c'
*/
static int	count_words(const char *s, char c)
{
	int	words;
	int	in_word;
	int	i;

	words = 0;	// counter
	in_word = 0;	// boolean, are we already in a word or not
	i = 0;		// index to iterate string 's'
	while (s[i] != '\0')
	{
		// if not in word and non-delimiter found,
		// we just entered a word, update boolean and counter
		if (!in_word && s[i] != c)
		{
			in_word = 1;
			++words;
		}
		// if in word and delimiter found,
		// we just left a word, update boolean
		else if (in_word && s[i] == c)
			in_word = 0;
		++i;
	}
	return (words);
}

/*
Auxiliary function to help use substring function.
It receives a string 's' that always includes a valid word,
and it may be preceded by a number of delimiter chars 'c'
It returns, through the use of pointers, 2 things:
1. Counts the length of the next valid word, including possible preceding delimiters into 'j'
2. Counts the length of the next valid word into 'len'
*/
static void	advance_index_len(char const *s, char c, int *j, int *len)
{
	*len = 0;
	while (s[*j] != '\0' && s[*j] == c)
		*j = *j + 1;
	while (s[*j] != '\0' && s[*j] != c)
	{
		*j = *j + 1;
		*len = *len + 1;
	}
}

/*
Auxiliary function to free all array elements (strings) until index 'stop'
Then, free the array itself
*/
static void	*free_everything(char **res, int stop)
{
	int	i;

	i = 0;
	while (i <= stop)
		free(res[i++]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;
	int		len;
	int		i;
	int		j;

	// Count words in order to allocate memory for the array
	word_count = count_words(s, c);
	// Allocate one extra pointer for the ending NULL
	res = malloc(sizeof(char *) * (word_count + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	// Iterate over words
	while (i < word_count)
	{
		// Function to find out starting index and length of the next valid word
		advance_index_len(s, c, &j, &len);
		// Allocate and copy word into array position 'i'
		res[i] = ft_substr(s, j - len, len);
		// If substring failed, free before returning to avoid leaks
		if (res[i] == NULL)
			return (free_everything(res, i), NULL);
		++i;
	}
	// Add NULL to end of array
	res[word_count] = NULL;
	return (res);
}
```

<h2>ft_itoa</h2>

```c
/*
This auxiliary function returns the length 'len' in characters
needed to represent the base 10 (decimal) number 'n'
*/
static size_t	num_length(int n)
{
	int		len;
	long	copy;

	if (n == 0)
		return (1);
	len = 0;
	copy = n;
	if (copy < 0)
	{
		++len;
		copy = -copy;
	}
	while (copy > 0)
	{
		copy /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*a;
	long	copy;
	int		len;

	len = num_length(n);
	a = malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	// Use a long variable to avoid problems with INT_MIN (-2147483648)
	copy = n;
	// Add zero ('0') char at first position if number is zero (0)
	if (copy == 0)
		a[0] = '0';
	// Add minus (-) char at position zero (0) if negative number
	if (copy < 0)
	{
		a[0] = '-';
		copy = -copy;
	}
	a[len--] = '\0';
	// Digits ('0' to '9') are added to the string/array from right to left
	while (copy > 0)
	{
		a[len--] = copy % 10 + '0';
		copy /= 10;
	}
	return (a);
}
```

<h2>ft_strmapi</h2>

```c
/*
This function creates a new string, where its characters result from applying
the function 'f' to every character of the string 's'.
The parameter string 's' should not be modified
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	// Allocate memory for new string 'res'
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	// Iterate the string 's'
	while (s[i] != '\0')
	{
		// Apply function 'f' to chars in 's' (not-in-place)
		// Assign the resulting chars to 'res' string
		res[i] = (*f)(i, s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}
```

<h2>ft_striteri</h2>

```c
/*
This function applies the function 'f' to every character
of the string 's', modifying the string in-place.
The parameter string 's' should be modified
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	// Iterate the string 's'
	while (s[i] != '\0')
	{
		// Apply function 'f' to every character from string
		// Function 'f' requires 2 parameters:
		// index, and pointer to current char
		(*f)(i, s + i); // Equivalent syntax: f(i, &s[i]);
		++i;
	}
}
```

<h2>ft_putchar_fd</h2>

```c
void	ft_putchar_fd(char c, int fd)
{
	// Write char
	write(fd, &c, 1);
}
```

<h2>ft_putstr_fd</h2>

```c
void	ft_putstr_fd(char *s, int fd)
{
	// Write string
	write(fd, s, ft_strlen(s));
}
```

<h2>ft_putendl_fd</h2>

```c
void	ft_putendl_fd(char *s, int fd)
{
	// Write string, then write '\n'
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
```

<h2>ft_putnbr_fd</h2>

```c
/*
This function prints a base 10 number 'n' into the file descriptor 'fd'
*/
void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	// To avoid problems when 'n' is INT_MIN (-2147483648), use long data type
	ln = n;
	// If number is zero (0), write it and exit function
	if (ln == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	// If number is negative, write minus (-) sign and make number positive
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln = -ln;
	}
	// If number has more than 1 digit, print all digits except the rightmost one
	// By recursively calling itself with number divided by 10
	if (ln > 9)
		ft_putnbr_fd((int)(ln / 10), fd);
	// Now print rightmost digit (ln % 10) as ASCII character ( + '0')
	ft_putchar_fd(ln % 10 + '0', fd);
}
```

<hr>

<h2>ft_lstnew</h2>

```c
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	// Allocate memory for new node
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	// Assign parameter 'content' into node->content
	// This is a generic pointer to anything in memory
	new_node->content = content;
	// The new node doesn't have next node
	// We explicitly initialize it with NULL
	new_node->next = NULL;
	return (new_node);
}
```

<h2>ft_lstadd_front</h2>

```c
/*
This function adds a node to the beginning of a linked list. In essence, there are 2 steps:
1. Assign the previous beginning of list to new node's next
2. Update list reference (aka first node's address) to new node
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	// Check if both lst and new exist
	if (lst == NULL || new == NULL)
		return ;
	// If list '*lst' isn't empty (first node is not NULL)
	// Assign the next of 'new' to beginning of list 'lst'
	// This 'if' can be removed and always do the assignment "new->next = *lst;"
	if (*lst != NULL)
		new->next = *lst;
	// Update list reference '*lst' to 'new' node
	// 'new->next' is already pointing to previous beginning of list '*lst' or NULL
	*lst = new;
}
```

<h2>ft_lstsize</h2>

```c
/*
This function counts the number of nodes in a linked list.
To do this, we iterate the list and increment a counter variable after every node we find
*/
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0; // counter variable
	// while node 'lst' exists (!= NULL), add to counter
	// (... && ++size) never affects the condition, and only happens if lst is not NULL
	while (lst && ++size)		// this trick saves lines by using short-circuit evaluation.
		lst = lst->next;	// then go to next node
	return (size);
}
// More about short-circuit evaluation: https://en.wikipedia.org/wiki/Short-circuit_evaluation
/* // A more readable way to write the while loop would have been:
while (lst)
{
  ++size;
  lst = lst->next;
}
*/
```

<h2>ft_lstsize</h2>

```c
/*
This function returns the last node of a linked list.
*/
t_list	*ft_lstlast(t_list *lst)
{
	// This condition allows us to iterate over the list nodes
	// and stop whenever the next node is NULL (lst must be the last node)
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
```

<h2>ft_lstadd_back</h2>

```c
/*
This function adds the node ’new’ at the end of the list.
Notice that we receive t_list **lst, so we are able to modify the list's reference
(change which one is the first node of the list)
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	// If there is no list or no new node, do nothing (early return)
	if (lst == NULL || new == NULL)
		return ;
	// If the list is empty, the new node becomes the first node of the list
	if (*lst == NULL)
		*lst = new;
	else	// Otherwise, the new node will be the next node of the last node
		ft_lstlast(*lst)->next = new;
}
```
