#include "ft_ls.h"

int		get_acl(char *file)
{
	acl_t	acl;

	if (!(acl = acl_get_file(file, ACL_TYPE_EXTENDED)))
		return (0);
	acl_free(acl);
	return (1);
}
