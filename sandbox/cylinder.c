/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:19:01 by mhernand          #+#    #+#             */
/*   Updated: 2019/09/18 17:19:14 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sandbox.h"

double  v_intersect_cy(t_vector ray, t_ol *ol, t_env *e)
{
    (void)e;
    (void)ol;
    (void)ray;
    double      t = 0;
    double      t_2 = 0;
    double      a = 0;
    double      b = 0;
    double      c = 0;
    double      det = 0;
    t_vector    tmp_dir = {ol->dir.x, ol->dir.y, ol->dir.z};
    t_vector    co;
    t_point     tmp_ray = {ray.x, ray.y, ray.z};
    t_point     tmp_po_cen = {ol->cen.x, ol->cen.y, ol->cen.z};
    t_vector    nor_dir; nor_dir.y = ol->dir.y; nor_dir.z = ol->dir.z; nor_dir.x = ol->dir.x;
    nor_dir = v_normalise(nor_dir);
    t_vector    nor_ray = v_normalise(ray);


    // V is a unit length vector that determines cylinder's axis

//    a   = D|D - (D|V)^2
//    b/2 = D|X - (D|V)*(X|V)
//    c   = X|X - (X|V)^2 - r*r

    co = create_v(e->cam.campos, tmp_po_cen);

    a = (v_scal(ray, nor_dir) * v_scal(ray, nor_dir)) - (cos(ol->angle) * cos(ol->angle));

    b = 2 * ((v_scal(ray, nor_dir) * v_scal(co, nor_dir)) - v_scal(ray, co) * (cos(ol->angle) * cos(ol->angle)));

    c = (v_scal(co, nor_dir) * v_scal(co, nor_dir)) - (v_scal(co, co) * (cos(ol->angle) * cos(ol->angle)));


    det = b * b - 4 * a * c;
    if (det < 0)
        return (0);
    if (det == 0)
        t = -b / 2 * a;
    else if (det > 0)
    {
        t = (-b + sqrt(det) )/ (2 * a);
        t_2 = (-b - sqrt(det)) / (2 * a);
        if (t <= 0 && t_2 <= 0)
            return (0);
        else
        {
            t = t < 0 ? t_2 : t;
            t = t < t_2 ? t : t_2;
        }
    }
    if (t < 0)
        return (0); //return val to be modified to send the closest valid solution
    else
        return (1);
    return (0);
}