/*
 * Copyright 2012 Jared Boone
 * Copyright 2013 Benjamin Vernoux
 *
 * This file is part of GreatFET.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include "usb_device.h"

#include <usb_type.h>

#include "usb_descriptor.h"

usb_configuration_t usb0_configuration_high_speed = {
	.number = 1,
	.speed = USB_SPEED_HIGH,
	.descriptor = usb0_descriptor_configuration_high_speed,
};

usb_configuration_t usb0_configuration_full_speed = {
	.number = 1,
	.speed = USB_SPEED_FULL,
	.descriptor = usb0_descriptor_configuration_full_speed,
};

usb_configuration_t* usb0_configurations[] = {
	&usb0_configuration_high_speed,
	&usb0_configuration_full_speed,
	0,
};

/* USB1 Experiment */
usb_configuration_t usb1_configuration_full_speed = {
	.number = 1,
	.speed = USB_SPEED_FULL,
	.descriptor = usb1_descriptor_configuration_full_speed,
};

usb_configuration_t* usb1_configurations[] = {
	&usb1_configuration_full_speed,
	0,
};

usb_device_t usb_devices[] = {
	{
		.descriptor = usb0_descriptor_device,
		.descriptor_strings = usb0_descriptor_strings,
		.qualifier_descriptor = usb0_descriptor_device_qualifier,
		.configurations = &usb0_configurations,
		.configuration = 0,
		.controller = 0,
	},
	{
		.descriptor = usb1_descriptor_device,
		.descriptor_strings = usb1_descriptor_strings,
		.qualifier_descriptor = usb1_descriptor_device_qualifier,
		.configurations = &usb1_configurations,
		.configuration = 0,
		.controller = 1,
	}
};
