/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_uv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omimouni <omimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:51:44 by omimouni          #+#    #+#             */
/*   Updated: 2021/02/09 09:38:13 by omimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		mrt_uv_sphere_calc(double *up, double *vp, t_pixel *p)
{
	double		u;
	double		v;
	t_vector3	p2;

	p2 = vec3_sub(p->hitpoint, ((t_sphere *)p->obj->object)->center);
	u = atan2(p2.x, p2.z) / (2 * M_PI);
	u = 1 - (u + 0.5);
	v = 1 - (acos(p2.y / (((t_sphere *)p->obj->object)->diameter / 2)) / M_PI);
	*up = floor(u * 16);
	*vp = floor(v * 8);
}

void			mrt_uv_sphere(t_pixel *p)
{
	double		u;
	double		v;

	mrt_uv_sphere_calc(&u, &v, p);
	if (fmod(u + v, 2) == 0)
		p->obj->color = color_from_rgb(0, 0, 0);
	else
		p->obj->color = color_from_rgb(255, 255, 255);
}
