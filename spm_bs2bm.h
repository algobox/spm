#ifndef SPM_BS2BM__
#define SPM_BS2BM__

#include "spm_cfg.h"

#define ALPHABET_SIZE 256

void Bs2BmBadchars(const uint8_t *, uint16_t, uint8_t *);
void Bs2BmBadcharsNocase(const uint8_t *, uint16_t, uint8_t *);
uint8_t * Bs2Bm(const uint8_t *, uint32_t, const uint8_t *, uint16_t, uint8_t []);
uint8_t *Bs2BmNocase(const uint8_t *, uint32_t, const uint8_t *, uint16_t, uint8_t []);

#endif /* SPM_BS2BM__ */

