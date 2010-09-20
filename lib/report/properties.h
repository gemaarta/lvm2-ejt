/*
 * Copyright (C) 2010 Red Hat, Inc. All rights reserved.
 *
 * This file is part of LVM2.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU Lesser General Public License v.2.1.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef _LVM_PROPERTIES_H
#define _LVM_PROPERTIES_H

#include "libdevmapper.h"
#include "lvm-types.h"
#include "metadata.h"

#define LVM_PROPERTY_NAME_LEN DM_REPORT_FIELD_TYPE_ID_LEN

struct lvm_property_type {
	char id[LVM_PROPERTY_NAME_LEN];
	unsigned is_writeable;
	unsigned is_string;
	union {
		char *s_val;
		uint64_t n_val;
	} v;
	int (*get) (void *obj, struct lvm_property_type *prop);
	int (*set) (void *obj, struct lvm_property_type *prop);
};

int vg_get_property(struct volume_group *vg, struct lvm_property_type *prop);

#endif