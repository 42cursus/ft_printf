/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:13:01 by abelov            #+#    #+#             */
/*   Updated: 2023/11/04 14:13:03 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strchr() function returns a pointer to the first occurrence of the
 * character c in the string s.
 * It returns a pointer to the matched character or NULL if the character
 * isn't found. The terminating null byte is considered part of the string,
 * so that if c is specified as '\0', the function returns a pointer to the NULL
 * terminator.
 */
char	*ft_strchr(const char *s, int chr)
{
	char	c;

	c = (char )chr;
	while (*s && (*s != c))
		s++;
	if (*s != c)
		return (NULL);
	return ((char *)s);
}

/**
 * The ft_strrchr() function returns a pointer to the last occurrence
 * of the character c in the string s.
 */
char	*ft_strrchr(const char *s, int chr)
{
	const char	*save = s;
	char		c;

	c = (char )chr;
	while (*s)
		s++;
	while ((s != save) && (*s != c))
		s--;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

/**
 *  The ft_strlcat() function concatenates strings. It take the full size of
 *  the buffer (not just the length) and guarantees to NUL-terminate the result
 *  (as long as there is at least one byte free in dst).
 *  ft_strlcat() only operate on true “C” strings.  This means that both src
 *  and dst must be NUL-terminated.
 *
 *  Returns the total length of the string tried to create.
 *  That means the initial length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	osize = size;
	char *const		odest = dest;
	size_t			dest_len;

	while (size-- && *dest)
		dest++;
	dest_len = dest - odest;
	if (dest_len >= osize)
		return (osize + ft_strlen(src));
	return (dest_len + ft_strlcpy(dest, src, osize - dest_len));
}


/**
 * The ft_strnstr() function locates the first occurrence of the null-terminated
 * string little in the string big, where not more than len characters are
 * searched. Characters that appear after a '\0' character are not searched.
 * If little is an empty string, big is returned; if little occurs nowhere in
 * big, NULL is returned; otherwise a pointer to the first character of
 * the first occurrence of little is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	char		*s;
	const char	*save = little;

	i = 0;
	s = (char *)big;
	if (big == little || !(*little))
		return (s);
	while ((len > 0) && *big)
	{
		s = (char *)big;
		little = save;
		i = 0;
		while ((*little++ == *s++) && (len != i++))
			if (*little == '\0')
				return ((char *)big);
		len--;
		big++;
	}
	return (NULL);
}

/**
 * Description:
 * 		Allocates (with malloc(3)) and returns a substring from the string 's'.
 * Parameters:
 * 		s: The string from which to create the substring.
 * 		start: The start index of the substring in the string `s`.
 * 		len: The maximum length of the substring.
 * Return value:
 * 		The substring.
 * 		NULL if the allocation fails.
 * The substring begins at index 'start' and is of maximum size 'len'.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	lenstr;
	size_t	remainder;

	if (!s)
		return (NULL);
	lenstr = ft_strlen(s);
	if (!lenstr || (start > lenstr) || !len)
		return ((char *)ft_calloc(1, sizeof(char)));
	remainder = lenstr - start;
	if (len < remainder)
		remainder = len;
	new = ((char *)ft_calloc(remainder + 1, sizeof(char)));
	if (!new)
		return (NULL);
	ft_strlcat(new, (s + start), remainder + 1);
	return (new);
}
