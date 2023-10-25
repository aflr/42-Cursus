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
</table>

<h2>Additional functions</h2>


<h2>Bonus functions</h2>


<h2>:white_check_mark: Everything passes francinette and francinette strict. :white_check_mark:</h2>

<h2>ft_isalpha</h2>

```
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
