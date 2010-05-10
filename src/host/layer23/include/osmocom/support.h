#ifndef _SUPPORT_H
#define _SUPPORT_H

#define GSM_CIPHER_A5_1		0
#define GSM_CIPHER_A5_2		1
#define GSM_CIPHER_A5_3		2
#define GSM_CIPHER_A5_4		3
#define GSM_CIPHER_A5_5		4
#define GSM_CIPHER_A5_6		5
#define GSM_CIPHER_A5_7		6
#define GSM_CIPHER_RESERVED	7

struct gsm_support {
	struct osmocom_ms *ms;

	/* rf power capability */
	uint8_t pwr_lev_900; /* and < 900 */
	uint8_t pwr_lev_1800; /* DCS and PCS */
	/* controlled early classmark sending */
	uint8_t es_ind;
	/* revision level */
	uint8_t rev_lev;
	/* support of VGCS */
	uint8_t vgcs;
	/* support of VBS */
	uint8_t vbs;
	/* support of SMS */
	uint8_t sms_ptp;
	/* screening indicator */
	uint8_t ss_ind;
	/* pseudo synchronised capability */
	uint8_t ps_cap;
	/* CM service prompt */
	uint8_t cmsp;
	/* solsa support */
	uint8_t solsa;
	/* location service support */
	uint8_t lcsva;
	/* codec supprot */
	uint8_t a5_1;
	uint8_t a5_2;
	uint8_t a5_3;
	uint8_t a5_4;
	uint8_t a5_5;
	uint8_t a5_6;
	uint8_t a5_7;
	/* radio support */
	uint8_t p_gsm;
	uint8_t e_gsm;
	uint8_t r_gsm;
	uint8_t r_capa;
	uint8_t low_capa;
	uint8_t dcs_1800;
	uint8_t dcs_capa;
	uint8_t freq_map[128];
	/* multi slot support */
	uint8_t ms_sup;
	/* ucs2 treatment */
	uint8_t ucs2_treat;
	/* support extended measurements */
	uint8_t ext_meas;
	/* support switched measurement capability */
	uint8_t meas_cap;
	uint8_t sms_val;
	uint8_t sm_val;
	/* positioning method capability */
	uint8_t loc_serv;
	uint8_t e_otd_ass;
	uint8_t e_otd_based;
	uint8_t gps_ass;
	uint8_t gps_based;
	uint8_t gps_conv;

	/* IMEI */
	char imei[15];
	char imeisv[17];
	char imei_random;

	/* radio */
	int8_t min_rxlev_db;
	uint8_t scan_to;
	uint8_t sync_to;
};

struct gsm_support_scan_max {
	uint16_t	start;
	uint16_t	end;
	uint16_t	max;
	uint16_t	temp;	
};
extern struct gsm_support_scan_max gsm_sup_smax[];

void gsm_support_init(struct osmocom_ms *ms);
void gsm_support_dump(struct gsm_support *sup,
			void (*print)(void *, const char *, ...), void *priv);

#endif /* _SUPPORT_H */
