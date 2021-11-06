#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr(const char *string, int searchedChar)
{
	char	*str;

	str = (char *)string;
	while (*str != (char) searchedChar)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

void	*ft_memcpy( void *destination, const void *source, size_t size )
{
	const unsigned char	*cast_src;
	unsigned char		*cast_dest;
	int					i;

	cast_src = (const unsigned char *) source;
	cast_dest = (unsigned char *) destination;
	i = 0;
	if ((size == 0) || (destination == source))
		return (destination);
	while ((size_t)i < size)
	{
		cast_dest[i] = cast_src[i];
		i++;
	}
	return ((void *)cast_dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	result[size] = '\0';
	ft_memcpy(result, s1, ft_strlen((char *)s1));
	ft_memcpy(result + ft_strlen((char *)s1), s2, ft_strlen((char *)s2));
	return (result);
}