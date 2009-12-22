/* LibMemcached
 * Copyright (C) 2006-2009 Brian Aker
 * All rights reserved.
 *
 * Use and distribution licensed under the BSD license.  See
 * the COPYING file in the parent directory for full text.
 *
 * Summary: Change the behavior of the memcached connection.
 *
 */

#ifndef __MEMCACHED_ANALYZE_H__
#define __MEMCACHED_ANALYZE_H__

#ifdef __cplusplus
extern "C" {
#endif


struct memcached_analysis_st {
  struct {
    bool allocated:1;
  } options;
  memcached_st *root;
  uint32_t average_item_size;
  uint32_t longest_uptime;
  uint32_t least_free_server;
  uint32_t most_consumed_server;
  uint32_t oldest_server;
  double pool_hit_ratio;
  uint64_t most_used_bytes;
  uint64_t least_remaining_bytes;
};


LIBMEMCACHED_API
memcached_analysis_st *memcached_analyze(memcached_st *memc,
                                         memcached_stat_st *memc_stat,
                                         memcached_return_t *error);

LIBMEMCACHED_API
void memcached_analyze_free(memcached_analysis_st *);

#ifdef __cplusplus
}
#endif

#endif /* __MEMCACHED_ANALYZE_H__ */
