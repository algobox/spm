#ifndef SPM_BM__
#define SPM_BM__

#include "spm_cfg.h"

#define ALPHABET_SIZE 256

/* Context for booyer moore */
typedef struct BmCtx_ {
    uint16_t bmBc[ALPHABET_SIZE];
    uint16_t *bmGs; // = SCMalloc(sizeof(int32_t)*(needlelen + 1));
} BmCtx;

/** Prepare and return a Boyer Moore context */
BmCtx *BoyerMooreCtxInit(uint8_t *needle, uint16_t needle_len);
BmCtx *BoyerMooreNocaseCtxInit(uint8_t *needle, uint16_t needle_len);

void BoyerMooreCtxToNocase(BmCtx *, uint8_t *, uint16_t);
uint8_t *BoyerMoore(uint8_t *x, uint16_t m, uint8_t *y, int32_t n, BmCtx *bm_ctx);
uint8_t *BoyerMooreNocase(uint8_t *x, uint16_t m, uint8_t *y, int32_t n, BmCtx *bm_ctx);
void BoyerMooreCtxDeInit(BmCtx *);

#endif /* __UTIL_SPM_BM__ */

