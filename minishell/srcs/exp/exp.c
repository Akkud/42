#include "minishell.h"
#include "libft.h"

int		exp_main(t_msh *data,char **word, int assign)
{
	t_exp		exp;
	int			ret;

	init_exp(&exp);
	exp.assign = assign;
	if (assign)
		find_tilde_exp_assign(data, word, exp);
	else
		find_tilde_exp(data, word, exp);
	ft_bzero(exp.buf, EXP_BSIZE);
	if ((ret = parse_param_exp(data, word, exp)) < 0)
		return (ret);
	return (1);
}
