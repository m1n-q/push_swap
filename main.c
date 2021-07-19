/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishin <mishin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 18:21:47 by mishin            #+#    #+#             */
/*   Updated: 2021/07/20 03:21:52 by mishin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# define DEBUG printf("upper_idx = (%d), lower_idx = (%d)\npivot = %lld\n<depth = %d>\n", upper_idx,lower_idx,pivot_val, depth);
# define PRT DEBUG print_all(stack);
# define PRT2 printf("upper_idx = (%d), lower_idx = (%d)\np1 = %lld, p2 = %lld\n", upper_idx,lower_idx, val.p1, val.p2); print_all(stack);


int	count;
int depth_count;

int	dual_qsort_a(t_set *stack, int upper_idx, int lower_idx, int depth)
{
	int	sub_size;
	int	rotated_while_find_small = 0;
	int	rotated_while_find_mid = 0;

	int	poped_while_find_small = 0;
	int	poped_while_find_mid = 0;

	int	i;
	t_vector_val	val;
	t_vector_idx	idx;
	int tmp = 0;


	idx = get_dual_pivot(stack->a, upper_idx, lower_idx);
	val.p1 = stack->a->data[idx.l];
	val.p2 = stack->a->data[idx.r];
	sub_size = upper_idx - lower_idx + 1;

	PRT2
	if (is_desc(stack->a, stack->a->top, 0) && is_asc(stack->b, stack->b->top, 0))
	{
		while (stack->b->top >= 0)
			pa;
		return (-1);
	}

	if (sub_size < 1)
		return (0);

	if (upper_idx < 0 || lower_idx < 0)
		return (0);

	if (is_desc(stack->a, upper_idx, lower_idx))
		return (0);

	if (sub_size == 1)
		count++;
/******************************************************************************/
	/*
		pivot 1 보다 작은 값 및 pivot 1 을 B 로 보내기
			O(sub_size) + 2
	*/

	i = -1;
	while (++i < sub_size)
	{
		if (stack->a->data[stack->a->top] <= val.p1)
		{
			pb;
			if (stack->b->data[stack->b->top] == val.p1)
				rb;
			poped_while_find_small++;
		}
		else
		{
			ra;
			rotated_while_find_small++;
		}
	}

	rrb;


	/*
		탐색한 만큼, 다시 돌려놓기.
			O(sub_size 2 / 3)
		돌리면서, 중간 값 및 pivot 2 를 B 로 보내기
			O(sub_size 1 / 3)
	*/
	i = -1;
	while (++i < rotated_while_find_small)
	{
		tmp = 1;
		rra;
		if (stack->a->data[stack->a->top] <= val.p2)
		{
			pb;
			if (stack->b->data[stack->b->top] == val.p2)
				rb;

			poped_while_find_mid++;
		}
	}
	if (tmp == 1)
		rrb;

	/// sub_size == 1 일땐 불필요한 연산 많네.

/******************************************************************************/
	if (depth > depth_count)
		depth_count = depth;

	if (-1 == dual_qsort_a(stack, stack->a->top, stack->a->top - (sub_size - poped_while_find_mid - poped_while_find_small) + 1, depth + 1))
		return -1;
	if (-1 == dual_qsort_b(stack, stack->b->top, stack->b->top - poped_while_find_mid + 1, depth + 1))
		return -1;
	if (-1 == dual_qsort_b(stack, stack->b->top, stack->b->top - poped_while_find_small + 1, depth + 1))
		return -1;

/******************************************************************************/
	return (0);
}






int	dual_qsort_b(t_set *stack, int upper_idx, int lower_idx, int depth)
{
	int	sub_size;

	int	rotated_while_find_mid = 0;
	int	rotated_while_find_large = 0;

	int	poped_while_find_mid = 0;
	int	poped_while_find_large = 0;
	int	i;
	t_vector_val	val;
	t_vector_idx	idx;
	int tmp = 0;
	idx =  get_dual_pivot(stack->b, upper_idx, lower_idx);
	val.p1 = stack->b->data[idx.l];
	val.p2 = stack->b->data[idx.r];

	sub_size = upper_idx - lower_idx + 1;
	PRT2

	if (is_desc(stack->a, stack->a->top, 0) && is_asc(stack->b, stack->b->top, 0))
	{
		while (stack->b->top >= 0)
			pa;
		return (-1);
	}

	if (sub_size < 1)
		return (0);


	if (sub_size == 1)
	{
		pa;
		return (0);
	}

	if (sub_size == 2)
	{
		if (stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 1])
			sb;
		pa;
		pa;
		return (0);
	}

	if (sub_size == 3)
	{
		count++;
		if (stack->b->data[stack->b->top - 2] < stack->b->data[stack->b->top - 1] && stack->b->data[stack->b->top - 1] < stack->b->data[stack->b->top])
			;

		else if (stack->b->data[stack->b->top - 2] < stack->b->data[stack->b->top] && stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 1])
			sb;

		else if (stack->b->data[stack->b->top - 1] < stack->b->data[stack->b->top - 2] && stack->b->data[stack->b->top - 2] < stack->b->data[stack->b->top])
		{
			rb;
			sb;
			rrb;
		}

		else if (stack->b->data[stack->b->top - 1] < stack->b->data[stack->b->top] && stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 2])
		{
			pa;
			sb;
			pb;
			sb;
		}
		else if (stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 1] && stack->b->data[stack->b->top - 1] < stack->b->data[stack->b->top - 2])
		{
			sb;
			pa;
			sb;
			pb;
			sb;
		}

		else if (stack->b->data[stack->b->top] < stack->b->data[stack->b->top - 2] && stack->b->data[stack->b->top - 2] < stack->b->data[stack->b->top - 1])
		{
			sb;
			pa;
			sb;
			pb;
		}


		pa;
		pa;
		pa;			// 어차피 넘어갈거면... 걍... 근데 이거 크리티컬하지않음. 500일때 사이즈 3인 경우가 얼마나 나올것이냐...? 170번 나온다 해. 연산을 10번씩 줄이면 1700 줄어들음. 10번 줄이는게 쉽나.?
					// 이거 연산 수 찍어보자 이부분 지웠을때 사이즈 3인경우, a로 넘어가는데에 얼마나 드는지 재보자.
		return (0);
	}

	if (upper_idx < 0 || lower_idx < 0)
		return (0);




/******************************************************************************/
	/*
		pivot 2 및 큰 값을 A 로 보내기
	*/

	i = -1;
	while (++i < sub_size)
	{
		if (stack->b->data[stack->b->top] >= val.p2)
		{
			pa;
			if (stack->a->data[stack->a->top] == val.p2)
				ra;
			poped_while_find_large++;
		}
		else
		{
			rb;
			rotated_while_find_large++;
		}
	}
	rra;

	/*
		되감으며, 중간값 및 pivot 1 을 a 로 보내기
	*/
	i = -1;
	while (++i < rotated_while_find_large)
	{
		tmp = 1;
		rrb;
		if (stack->b->data[stack->b->top] >= val.p1)
		{
			pa;
			if (stack->a->data[stack->a->top] == val.p1)
				ra;
			poped_while_find_mid++;
		}
	}
	if (tmp == 1)
		rra;

	if (depth > depth_count)
		depth_count = depth;


	if (-1 == dual_qsort_a(stack, stack->a->top, stack->a->top - (poped_while_find_large + poped_while_find_mid) + 1, depth + 1))
		return -1;

	// 여기서, 몇번 재귀를 하든 결국 A 로 다 치워놓게 됨? (pb로 돌려놓는 과정이 없으니까 ?)

	if (-1 == dual_qsort_b(stack, stack->b->top, stack->b->top - (sub_size - poped_while_find_mid - poped_while_find_large) + 1, depth + 1))
		return -1;

	// 그럼, 남은 부분 다시 할수 있찌?
	// 그럼, 결국 qsort_b 는 top 에서만 진행된다 ?


/******************************************************************************/

	return (0);
}





int	main(int argc, char **argv)
{
	int			i;
	long long	is_int;
	t_set		stack;

	i = argc;
	if (argc < 2)
		return 1;
	if ((stack.a = init_stack(argc - 1)) == NULL)
		return 2;
	if ((stack.b = init_stack(argc - 1)) == NULL)
		return 2;
	while (--i > 0)
	{
		if ((is_int = ft_atoi(argv[i])) == OVER_INTEGER)
			return 3;
		else
			push(stack.a, is_int);
	}


	/* 700 , 5500 */


	dual_qsort_a(&stack, stack.a->top, 0, 0);
	printf("count : %d\ndepth count : %d\n", count, depth_count);
	// print_all(&stack);

}








/*

	 ./push_swap 24 226 181 325 190 206 310 196 386 290 409 133 269 455 265 178 219 22 486 371 192 264 211 418 359 139 241 312 353 176 149 275 381 289 337 357 5 143 21 254 388 435 231 201 343 450 426 31 50 485 224 392 37 328 286 414 416 484 239 33 48 171 368 124 188 1 184 174 270 446 128 451 83 136 9 493 191 423 54 99 151 400 82 109 475 56 417 340 268 58 110 376 481 69 436 273 71 203 216 346 65 60 103 148 300 78 189 390 464 478 462 250 42 30 402 152 260 429 301 470 298 117 155 53 369 89 367 74 274 193 374 332 73 87 398 315 442 482 67 86 81 44 441 244 121 294 488 272 379 349 284 499 384 47 13 480 497 179 271 431 23 363 169 213 88 80 129 385 467 29 447 404 295 200 113 227 277 428 51 334 76 358 107 243 396 17 410 297 16 187 259 100 0 433 130 465 356 498 183 344 445 182 52 461 64 327 397 39 46 61 362 127 360 154 141 266 85 276 319 249 456 383 424 106 91 296 77 222 55 377 281 177 262 195 157 232 165 477 415 351 329 228 339 457 57 330 236 306 145 466 137 209 352 242 320 443 453 104 18 406 479 161 235 72 245 304 490 419 448 341 93 287 494 126 6 135 202 116 439 27 32 348 422 411 401 112 217 160 292 43 167 489 430 311 131 382 96 394 210 70 263 118 185 19 142 221 11 132 321 204 267 335 237 15 212 372 342 159 326 279 317 10 468 248 246 373 123 95 119 309 336 215 120 168 452 438 66 361 20 3 347 366 247 153 97 79 350 476 111 458 483 170 463 316 355 283 12 258 491 146 324 208 399 25 225 405 138 364 59 318 214 412 114 156 387 492 162 471 140 495 101 234 375 223 172 257 380 331 282 38 354 305 299 314 285 291 288 41 487 469 98 194 92 252 49 164 68 255 391 150 460 308 403 163 302 365 14 473 198 496 293 333 251 413 180 199 197 389 134 220 35 238 421 427 115 34 454 437 345 166 2 378 207 75 28 7 230 62 108 158 90 434 102 105 253 395 240 444 474 36 261 425 94 280 407 40 449 125 313 420 323 173 122 408 229 84 370 338 205 307 147 186 440 472 233 256 4 459 63 8 175 45 432 26 278 218 303 144 393 322 | wc -l
    8470


*/
