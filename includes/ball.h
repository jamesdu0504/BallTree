/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <elee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 10:55:27 by elee              #+#    #+#             */
/*   Updated: 2017/06/28 17:20:17 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BALL_H
# define BALL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <math.h>
# include <float.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_nheap
{
	double		**distances;
	int			**indices;
	int			n_pts;
	int			n_nbrs;
}				t_nheap;

typedef struct	s_knn
{
	double		**distances;
	int			**indices;
}				t_knn;

typedef	struct	s_nodedata
{
	int			idx_start;
	int			idx_end;
	int			is_leaf;
	double		radius;
}				t_nodedata;

typedef struct	s_btree
{
	double		**data;
	int			*idx_array;
	t_nodedata	*node_data;
	double		***node_bounds;

	int			n_samples;
	int			n_features;

	int			leaf_size;
	int			n_levels;
	int			n_nodes;

	int			n_trims;
	int			n_leaves;
	int			n_splits;
	int			n_calls;
}				t_btree;


/*
** metrics.c
*/

double	manhattan_dist(double *x1, double *x2, int size);
double	min_dist(t_btree *tree, int i_node, double *pt);

/*
** neighbors_heap.c
*/

t_nheap	*nheap_init(int n_pts, int n_nbrs);
double	nheap_largest(t_nheap *h, int row);
int		nheap_push(t_nheap *h, int row, double val, int i_val);
t_knn	nheap_get_arrays(t_nheap *h);

/*
** ball.c
*/

t_btree	*btree_init(double **data, int n_samples, int n_features, int leaf_size);
t_knn	btree_query(t_btree *b, double **x, int n_samples, int n_features, int k);
#endif
