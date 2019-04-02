#include "ft_printf.h"

static int	datalloc(t_printf **data)
{
	if (*data)
	{
		if (!(*(data)->next = (t_printf*)malloc(sizeof(t_printf))))
			return (0);
		*data = *(data)->next;
	}
	else
		if (!(*data = (t_printf*)malloc(sizeof(t_printf))))
			return (0);
	data->flag = "00000";
	data->fw = NULL;
	data->pres = NULL;
	data->lmod = 0;
	
	
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	t_printf *data;

	data = NULL;
	va_start(ap, format);
	while (*format)
	{
		if (*format++ == '%')
		{
			ft_datalloc(&data);
			ft_cflag(&format, data);
			ft_cfw(&format, data);
			ft_cpres(&format, data);
			ft_clmod(&format, data);
			ft_cconv(&format, data);
		}
	}
	ft_putstr(
	va_end(ap);
	return ();
}

int		main()
{





}
