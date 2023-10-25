<h1 align="center"> 🚧 README under construction 🚧 </h1>

<h1 align="center">libft</h1>

<blockquote>This project is about coding a C library. It will contain a lot of general purpose functions your programs will rely upon.</blockquote>

<h2 align="center">
  <a href="#libc-functions">Libc functions</a>
  ·
  <a href="#additional-functions">Additional functions</a>
  ·
  <a href="#bonus-functions">Bonus functions</a>
</h2>

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
    <td>Checks if the given character is an alphabetic character, i.e. either an uppercase or lowercase letter</td>
    <td><a href="#ft_isalpha">Explained</a></td>
    <td><a href="https://github.com/aflr/42-Cursus/blob/main/libft/ft_isalpha.c">ft_isalpha.c</a></td>
  </tr>
  <tr>
    <td>ft_isdigit</td>
    <td>&lt;ctype.h&gt;</td>
    <td>Checks for a digit (0 through 9)</td>
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
</table>

<h2>Bonus functions</h2>


<h2>:white_check_mark: Everything passes francinette and francinette strict. :white_check_mark:</h2>

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
	// 'i' is the index where we stopped copying 's1'
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	// All strings in C must end with a null terminator, the character '\0'
	res[i] = '\0';
	return (res);
}
```
