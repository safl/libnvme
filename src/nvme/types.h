// SPDX-License-Identifier: LGPL-2.1-or-later
/*
 * This file is part of libnvme.
 * Copyright (c) 2020 Western Digital Corporation or its affiliates.
 *
 * Authors: Keith Busch <keith.busch@wdc.com>
 * 	    Chaitanya Kulkarni <chaitanya.kulkarni@wdc.com>
 */

#ifndef _LIBNVME_TYPES_H
#define _LIBNVME_TYPES_H

#include <endian.h>
#include <stdbool.h>
#include <stdint.h>

#include <linux/types.h>

#ifdef __CHECKER__
#define __force       __attribute__((force))
#else
#define __force
#endif

/**
 * cpu_to_le16() -
 * @x: 16-bit CPU value to turn to little endian.
 */
static inline __le16 cpu_to_le16(uint16_t x)
{
	return (__force __le16)htole16(x);
}

/**
 * cpu_to_le32() -
 * @x: 32-bit CPU value to turn little endian.
 */
static inline __le32 cpu_to_le32(uint32_t x)
{
	return (__force __le32)htole32(x);
}

/**
 * cpu_to_le64() -
 * @x: 64-bit CPU value to turn little endian.
 */
static inline __le64 cpu_to_le64(uint64_t x)
{
	return (__force __le64)htole64(x);
}

/**
 * le16_to_cpu() -
 * @x: 16-bit little endian value to turn to CPU.
 */
static inline uint16_t le16_to_cpu(__le16 x)
{
	return le16toh((__force __u16)x);
}

/**
 * le32_to_cpu() -
 * @x: 32-bit little endian value to turn to CPU.
 */
static inline uint32_t le32_to_cpu(__le32 x)
{
	return le32toh((__force __u32)x);
}

/**
 * le64_to_cpu() -
 * @x: 64-bit little endian value to turn to CPU.
 */
static inline uint64_t le64_to_cpu(__le64 x)
{
	return le64toh((__force __u64)x);
}

/**
 * enum nvme_constants - A place to stash various constant nvme values
 * @NVME_NSID_ALL:		A broadcast value that is used to specify all
 * 				namespaces
 * @NVME_NSID_NONE:		The invalid namespace id, for when the nsid
 * 				parameter is not used in a command
 * @NVME_UUID_NONE:		Use to omit the uuid command parameter
 * @NVME_CNTLID_NONE:		Use to omit the cntlid command parameter
 * @NVME_NVMSETID_NONE: 	Use to omit the nvmsetid command parameter
 * @NVME_LOG_LSP_NONE:		Use to omit the log lsp command parameter
 * @NVME_LOG_LSI_NONE:		Use to omit the log lsi command parameter
 * @NVME_IDENTIFY_DATA_SIZE:	The transfer size for nvme identify commands
 * @NVME_ID_NVMSET_LIST_MAX:	The largest possible nvmset index in identify
 * 				nvmeset
 * @NVME_ID_UUID_LIST_MAX:	The largest possible uuid index in identify
 * 				uuid list
 * @NVME_ID_CTRL_LIST_MAX:	The largest possible controller index in
 * 				identify controller list
 * @NVME_ID_NS_LIST_MAX:	The largest possible namespace index in
 * 				identify namespace list
 * @NVME_ID_SECONDARY_CTRL_MAX:	The largest possible secondary controller index
 * 				in identify secondary controller
 * @NVME_FEAT_LBA_RANGE_MAX:	The largest possible LBA range index in feature
 * 				lba range type
 * @NVME_LOG_ST_MAX_RESULTS:	The largest possible self test result index in the
 * 				device self test log
 * @NVME_LOG_TELEM_BLOCK_SIZE:	Specification defined size of Telemetry Data Blocks
 * @NVME_DSM_MAX_RANGES:	The largest possible range index in a data-set
 * 				management command
 * @NVME_NQN_LENGTH:		Max length for NVMe Qualified Name.
 * @NVMF_TRADDR_SIZE:
 * @NVMF_TSAS_SIZE:
 */
enum nvme_constants {
	NVME_NSID_ALL			= 0xffffffff,
	NVME_NSID_NONE			= 0,
	NVME_UUID_NONE			= 0,
	NVME_CNTLID_NONE		= 0,
	NVME_NVMSETID_NONE		= 0,
	NVME_LOG_LSP_NONE		= 0,
	NVME_LOG_LSI_NONE		= 0,
	NVME_IDENTIFY_DATA_SIZE		= 4096,
	NVME_ID_NVMSET_LIST_MAX		= 31,
	NVME_ID_UUID_LIST_MAX		= 127,
	NVME_ID_CTRL_LIST_MAX		= 2047,
	NVME_ID_NS_LIST_MAX		= 1024,
	NVME_ID_SECONDARY_CTRL_MAX	= 127,
	NVME_ID_ND_DESCRIPTOR_MAX	= 16,
	NVME_FEAT_LBA_RANGE_MAX		= 64,
	NVME_LOG_ST_MAX_RESULTS		= 20,
	NVME_LOG_TELEM_BLOCK_SIZE	= 512,
	NVME_DSM_MAX_RANGES		= 256,
	NVME_NQN_LENGTH			= 256,
	NVMF_TRADDR_SIZE		= 256,
	NVMF_TSAS_SIZE			= 256,
	NVME_NIDT_EUI64_LEN		= 8,
	NVME_NIDT_NGUID_LEN		= 16,
};

/**
 * enum nvme_register_offsets - The nvme controller registers for all transports. This
 * 				is the layout of BAR0/1 for PCIe, and
 * 				properties for fabrics.
 * @NVME_REG_CAP:	Controller Capabilities
 * @NVME_REG_VS:	Version
 * @NVME_REG_INTMS:	Interrupt Mask Set
 * @NVME_REG_INTMC:	Interrupt Mask Clear
 * @NVME_REG_CC:	Controller Configuration
 * @NVME_REG_CSTS:	Controller Status
 * @NVME_REG_NSSR:	NVM Subsystem Reset
 * @NVME_REG_AQA:	Admin Queue Attributes
 * @NVME_REG_ASQ:	Admin SQ Base Address
 * @NVME_REG_ACQ:	Admin CQ Base Address
 * @NVME_REG_CMBLOC:	Controller Memory Buffer Location
 * @NVME_REG_CMBSZ:	Controller Memory Buffer Size
 * @NVME_REG_BPINFO:	Boot Partition Information
 * @NVME_REG_BPRSEL:	Boot Partition Read Select
 * @NVME_REG_BPMBL:	Boot Partition Memory Buffer Location
 * @NVME_REG_CMBMSC:	Controller Memory Buffer Memory Space Control
 * @NVME_REG_CMBSTS:	Controller Memory Buffer Status
 * @NVME_REG_PMRCAP:	Persistent Memory Capabilities
 * @NVME_REG_PMRCTL:	Persistent Memory Region Control
 * @NVME_REG_PMRSTS:	Persistent Memory Region Status
 * @NVME_REG_PMREBS:	Persistent Memory Region Elasticity Buffer Size
 * @NVME_REG_PMRSWTP:	Memory Region Sustained Write Throughput
 * @NVME_REG_PMRMSC:	Persistent Memory Region Controller Memory Space Control
 * @NVME_REG_DBS:	SQ 0 Tail Doorbell
 */
enum nvme_register_offsets {
	NVME_REG_CAP	= 0x0000,
	NVME_REG_VS	= 0x0008,
	NVME_REG_INTMS	= 0x000c,
	NVME_REG_INTMC	= 0x0010,
	NVME_REG_CC	= 0x0014,
	NVME_REG_CSTS	= 0x001c,
	NVME_REG_NSSR	= 0x0020,
	NVME_REG_AQA	= 0x0024,
	NVME_REG_ASQ	= 0x0028,
	NVME_REG_ACQ	= 0x0030,
	NVME_REG_CMBLOC = 0x0038,
	NVME_REG_CMBSZ	= 0x003c,
	NVME_REG_BPINFO	= 0x0040,
	NVME_REG_BPRSEL	= 0x0044,
	NVME_REG_BPMBL	= 0x0048,
	NVME_REG_CMBMSC	= 0x0050,
	NVME_REG_CMBSTS	= 0x0058,
	NVME_REG_PMRCAP = 0x0e00,
	NVME_REG_PMRCTL = 0x0e04,
	NVME_REG_PMRSTS = 0x0e08,
	NVME_REG_PMREBS = 0x0e0c,
	NVME_REG_PMRSWTP= 0x0e10,
	NVME_REG_PMRMSC = 0x0e14,
	NVME_REG_DBS	= 0x1000,
};

#define NVME_CAP_MQES(cap)	((cap) & 0xffff)
#define NVME_CAP_CQR(cap)	(((cap) >> 16) & 0x1)
#define NVME_CAP_AMS(cap)	(((cap) >> 17) & 0x3)
#define NVME_CAP_TIMEOUT(cap)	(((cap) >> 24) & 0xff)
#define NVME_CAP_STRIDE(cap)	(((cap) >> 32) & 0xf)
#define NVME_CAP_NSSRC(cap)	(((cap) >> 36) & 0x1)
#define NVME_CAP_CSS(cap)	(((cap) >> 37) & 0xff)
#define NVME_CAP_BPS(cap)	(((cap) >> 45) & 0x1)
#define NVME_CAP_MPSMIN(cap)	(((cap) >> 48) & 0xf)
#define NVME_CAP_MPSMAX(cap)	(((cap) >> 52) & 0xf)
#define NVME_CAP_CMBS(cap)	(((cap) >> 57) & 1)
#define NVME_CAP_PMRS(cap)	(((cap) >> 56) & 1)

#define NVME_CMB_BIR(cmbloc)	((cmbloc) & 0x7)
#define NVME_CMB_OFST(cmbloc)	(((cmbloc) >> 12) & 0xfffff)
#define NVME_CMB_SZ(cmbsz)	(((cmbsz) >> 12) & 0xfffff)
#define NVME_CMB_SZU(cmbsz)	(((cmbsz) >> 8) & 0xf)

#define NVME_CMB_WDS(cmbsz)	((cmbsz) & 0x10)
#define NVME_CMB_RDS(cmbsz)	((cmbsz) & 0x8)
#define NVME_CMB_LISTS(cmbsz)	((cmbsz) & 0x4)
#define NVME_CMB_CQS(cmbsz)	((cmbsz) & 0x2)
#define NVME_CMB_SQS(cmbsz)	((cmbsz) & 0x1)

enum {
	NVME_CC_ENABLE		= 1 << 0,
	NVME_CC_CSS_NVM		= 0 << 4,
	NVME_CC_EN_SHIFT	= 0,
	NVME_CC_CSS_SHIFT	= 4,
	NVME_CC_MPS_SHIFT	= 7,
	NVME_CC_AMS_SHIFT	= 11,
	NVME_CC_SHN_SHIFT	= 14,
	NVME_CC_IOSQES_SHIFT	= 16,
	NVME_CC_IOCQES_SHIFT	= 20,
	NVME_CC_AMS_RR		= 0 << NVME_CC_AMS_SHIFT,
	NVME_CC_AMS_WRRU	= 1 << NVME_CC_AMS_SHIFT,
	NVME_CC_AMS_VS		= 7 << NVME_CC_AMS_SHIFT,
	NVME_CC_SHN_NONE	= 0 << NVME_CC_SHN_SHIFT,
	NVME_CC_SHN_NORMAL	= 1 << NVME_CC_SHN_SHIFT,
	NVME_CC_SHN_ABRUPT	= 2 << NVME_CC_SHN_SHIFT,
	NVME_CC_SHN_MASK	= 3 << NVME_CC_SHN_SHIFT,
	NVME_CSTS_RDY		= 1 << 0,
	NVME_CSTS_CFS		= 1 << 1,
	NVME_CSTS_NSSRO		= 1 << 4,
	NVME_CSTS_PP		= 1 << 5,
	NVME_CSTS_SHST_NORMAL	= 0 << 2,
	NVME_CSTS_SHST_OCCUR	= 1 << 2,
	NVME_CSTS_SHST_CMPLT	= 2 << 2,
	NVME_CSTS_SHST_MASK	= 3 << 2,
};

/**
 * nvme_is_64bit_reg() - Checks if offset of the controller register is a know
 * 			 64bit value.
 * @offset:	Offset of controller register field in bytes
 *
 * This function does not care about transport so that the offset is not going
 * to be checked inside of this function for the unsupported fields in a
 * specific transport. For example, BPMBL(Boot Partition Memory Buffer
 * Location) register is not supported by fabrics, but it can be chcked here.
 *
 * Returns true if given offset is 64bit register, otherwise it returns false.
 */
static inline bool nvme_is_64bit_reg(__u32 offset)
{
	switch (offset) {
	case NVME_REG_CAP:
	case NVME_REG_ASQ:
	case NVME_REG_ACQ:
	case NVME_REG_BPMBL:
		return true;
	default:
		return false;
	}
}

/**
 * enum nvme_psd_flags - Possible flag values in nvme power state descriptor
 * @NVME_PSD_FLAGS_MXPS: Indicates the scale for the Maximum Power
 * 			 field. If this bit is cleared, then the scale of the
 * 			 Maximum Power field is in 0.01 Watts. If this bit is
 * 			 set, then the scale of the Maximum Power field is in
 * 			 0.0001 Watts.
 * @NVME_PSD_FLAGS_NOPS: Indicates whether the controller processes I/O
 * 			 commands in this power state. If this bit is cleared,
 * 			 then the controller processes I/O commands in this
 * 			 power state. If this bit is set, then the controller
 * 			 does not process I/O commands in this power state.
 */
enum nvme_psd_flags {
	 NVME_PSD_FLAGS_MXPS		= 1 << 0,
	 NVME_PSD_FLAGS_NOPS		= 1 << 1,
};

/**
 * enum nvme_psd_ps - Known values for &struct nvme_psd #ips and #aps. Use with
 * 		      nvme_psd_power_scale() to extract the power scale field
 * 		      to match this enum.
 * NVME_PSD_IPS_100_MICRO_WATT:	0.0001 watt scale
 * NVME_PSD_IPS_10_MILLI_WATT:	0.01 watt scale
 */
enum nvme_psd_ps {
	 NVME_PSD_PS_100_MICRO_WATT	= 1,
	 NVME_PSD_PS_10_MILLI_WATT	= 2,
};

/**
 * nvme_psd_power_scale() - power scale occupies the upper 3 bits
 */
static inline unsigned nvme_psd_power_scale(__u8 ps)
{
	return ps >> 6;
}

/**
 * enum nvme_psd_workload - Specifies a workload hint in the Power Management
 * 			    Feature (see &struct nvme_psd.apw) to inform the
 * 			    NVM subsystem or indicate the conditions for the
 * 			    active power level.
 * @NVME_PSD_WORKLOAD_1: Extended Idle Period with a Burst of Random Write
 * 			 consists of five minutes of idle followed by
 * 			 thirty-two random write commands of size 1 MiB
 * 			 submitted to a single controller while all other
 * 			 controllers in the NVM subsystem are idle, and then
 * 			 thirty (30) seconds of idle.
 * @NVME_PSD_WORKLOAD_2: Heavy Sequential Writes consists of 80,000
 *			 sequential write commands of size 128 KiB submitted to
 *			 a single controller while all other controllers in the
 *			 NVM subsystem are idle.  The submission queue(s)
 *			 should be sufficiently large allowing the host to
 *			 ensure there are multiple commands pending at all
 *			 times during the workload.
 */
enum nvme_psd_workload {
	 NVME_PSD_WORKLOAD_1	= 1,
	 NVME_PSD_WORKLOAD_2	= 2,
};

/**
 * struct nvme_id_psd -
 * @mp:	   Maximum Power indicates the sustained maximum power consumed by the
 * 	   NVM subsystem in this power state. The power in Watts is equal to
 * 	   the value in this field multiplied by the scale specified in the Max
 * 	   Power Scale bit (see &enum nvme_psd_flags). A value of 0 indicates
 * 	   Maximum Power is not reported.
 * @flags: Additional decoding flags, see &enum nvme_psd_flags.
 * @enlat: Entry Latency indicates the maximum latency in microseconds
 * 	   associated with entering this power state. A value of 0 indicates
 * 	   Entry Latency is not reported.
 * @exlat: Exit Latency indicates the maximum latency in microseconds
 * 	   associated with exiting this power state. A value of 0 indicates
 * 	   Exit Latency is not reported.
 * @rrt:   Relative Read Throughput indicates the read throughput rank
 * 	   associated with this power state relative to others. The value in
 * 	   this is less than the number of supported power states.
 * @rrl:   Relative Reade Latency indicates the read latency rank associated
 * 	   with this power state relative to others. The value in this field is
 * 	   less than the number of supported power states.
 * @rwt:   Relative Write Throughput indicates write throughput rank associated
 * 	   with this power state relative to others. The value in this field is
 * 	   less than the number of supported power states
 * @rwl:   Relative Write Latency indicates the write latency rank associated
 * 	   with this power state relative to others. The value in this field is
 * 	   less than the number of supported power states
 * @idlp:  Idle Power indicates the typical power consumed by the NVM
 * 	   subsystem over 30 seconds in this power state when idle.
 * @ips:   Idle Power Scale indicates the scale for &struct nvme_id_psd.idlp,
 * 	   see &enum nvme_psd_ps for decoding this field.
 * @actp:  Active Power indicates the largest average power consumed by the
 * 	   NVM subsystem over a 10 second period in this power state with
 * 	   the workload indicated in the Active Power Workload field.
 * @apw:   Active Power Workload indicates the workload used to calculate
 * 	   maximum power for this power state. See &enum nvme_psd_workload for
 * 	   decoding this field.
 * @aps:   Active Power Scale indicates the scale for the &struct
 * 	   nvme_id_psd.actp, see &enum nvme_psd_ps for decoding this value.
 */
struct nvme_id_psd {
	__le16			mp;
	__u8			rsvd2;
	__u8			flags;
	__le32			enlat;
	__le32			exlat;
	__u8			rrt;
	__u8			rrl;
	__u8			rwt;
	__u8			rwl;
	__le16			idlp;
	__u8			ips;
	__u8			rsvd19;
	__le16			actp;
	__u8			apw;
	__u8			aps;
	__u8			rsvd23[8];
};

/**
 * struct nvme_id_ctrl - Identify Controller data structure
 * @vid:       PCI Vendor ID, the company vendor identifier that is assigned by
 * 	       the PCI SIG.
 * @ssvid:     PCI Subsystem Vendor ID, the company vendor identifier that is
 * 	       assigned by the PCI SIG for the subsystem.
 * @sn:        Serial Number in ascii
 * @mn:        Model Number in ascii
 * @fr:        Firmware Revision in ascii, the currently active firmware
 * 	       revision for the NVM subsystem
 * @rab:       Recommended Arbitration Burst, reported as a power of two
 * @ieee:      IEEE assigned Organization Unique Identifier
 * @cmic:      Controller Multipath IO and Namespace Sharing  Capabilities of
 * 	       the controller and NVM subsystem. See &enum nvme_id_ctrl_cmic.
 * @mdts:      Max Data Transfer Size is the largest data transfer size. The
 * 	       host should not submit a command that exceeds this maximum data
 * 	       transfer size. The value is in units of the minimum memory page
 * 	       size (CAP.MPSMIN) and is reported as a power of two
 * @cntlid:    Controller ID, the NVM subsystem unique controller identifier
 * 	       associated with the controller.
 * @ver:       Version, this field contains the value reported in the Version
 * 	       register, or property (see &enum nvme_registers %NVME_REG_VS).
 * @rtd3r:     RTD3 Resume Latency, the expected latency in microseconds to resume
 * 	       from Runtime D3
 * @rtd3e:     RTD3 Exit Latency, the typical latency in microseconds to enter
 * 	       Runtime D3.
 * @oaes:      Optional Async Events Supported, see @enum nvme_id_ctrl_oaes .
 * @ctratt:    Controller Attributes, see @enum nvme_id_ctrl_ctratt
 * @rrls:      Read Recovery Levels. If a bit is set, then the corresponding
 * 	       Read Recovery Level is supported. If a bit is cleared, then the
 * 	       corresponding Read Recovery Level is not supported.
 * @cntrltype: Controller Type, see &enum nvme_id_ctrl_cntrltype
 * @fguid:     FRU GUID, a 128-bit value that is globally unique for a given
 * 	       Field Replaceable Unit
 * @crdt1:     Controller Retry Delay time in 100 millisecod units if CQE CRD
 *	       field is 1
 * @crdt2:     Controller Retry Delay time in 100 millisecod units if CQE CRD
 * 	       field is 2
 * @crdt3:     Controller Retry Delay time in 100 millisecod units if CQE CRD
 * 	       field is 3
 * @nvmsr:     NVM Subsystem Report, see &enum nvme_id_ctrl_nvmsr
 * @vwci:      VPD Write Cycle Information, see &enum nvme_id_ctrl_vwci
 * @mec:       Management Endpoint Capabilities, see &enum nvme_id_ctrl_mec
 * @oacs:      Optional Admin Command Support,the optional Admin commands and
 * 	       features supported by the controller, see &enum nvme_id_ctrl_oacs.
 * @acl:       Abort Command Limit, the maximum number of concurrently
 * 	       executing Abort commands supported by the controller. This is a
 * 	       0's based value.
 * @aerl:      Async Event Request Limit, the maximum number of concurrently
 * 	       outstanding Asynchronous Event Request commands supported by the
 * 	       controller This is a 0's based value.
 * @frmw:      Firmware Updates indicates capabilities regarding firmware
 * 	       updates. See &enum nvme_id_ctrl_frmw.
 * @lpa:       Log Page Attributes, see &enum nvme_id_ctrl_lpa.
 * @elpe:      Error Log Page Entries, the maximum number of Error Information
 * 	       log entries that are stored by the controller. This field is a
 * 	       0's based value.
 * @npss:      Number of Power States Supported, the number of NVM Express
 * 	       power states supported by the controller, indicating the number
 * 	       of valid entries in &struct nvme_id_ctrl.psd. This is a 0's
 * 	       based value.
 * @avscc:     Admin Vendor Specific Command Configuration, see
 * 	       &enum nvme_id_ctrl_avscc.
 * @apsta:     Autonomous Power State Transition Attributes, see
 * 	       &enum nvme_id_ctrl_apsta.
 * @wctemp:    Warning Composite Temperature Threshold indicates
 * 	       the minimum Composite Temperature field value (see &struct
 * 	       nvme_smart_log.critical_comp_time) that indicates an overheating
 * 	       condition during which controller operation continues.
 * @cctemp:    Critical Composite Temperature Threshold, field indicates the
 * 	       minimum Composite Temperature field value (see &struct
* 	       nvme_smart_log.critical_comp_time) that indicates a critical
 * 	       overheating condition.
 * @mtfa:      Maximum Time for Firmware Activation indicates the maximum time
 * 	       the controller temporarily stops processing commands to activate
 * 	       the firmware image, specified in 100 millisecond units. This
 * 	       field is always valid if the controller supports firmware
 * 	       activation without a reset.
 * @hmpre:     Host Memory Buffer Preferred Size indicates the preferred size
 * 	       that the host is requested to allocate for the Host Memory
 * 	       Buffer feature in 4 KiB units.
 * @hmmin:     Host Memory Buffer Minimum Size indicates the minimum size that
 * 	       the host is requested to allocate for the Host Memory Buffer
 * 	       feature in 4 KiB units.
 * @tnvmcap:   Total NVM Capacity, the total NVM capacity in the NVM subsystem.
 * 	       The value is in bytes.
 * @unvmcap:   Unallocated NVM Capacity, the unallocated NVM capacity in the
 * 	       NVM subsystem. The value is in bytes.
 * @rpmbs      Replay Protected Memory Block Support, see
 * 	       &enum nvme_id_ctrl_rpmbs.
 * @edstt      Extended Device Self-test Time, if Device Self-test command is
 * 	       supported (see &struct nvme_id_ctrl.oacs, %NVME_CTRL_OACS_SELF_TEST),
 * 	       then this field indicates the nominal amount of time in one
 * 	       minute units that the controller takes to complete an extended
 * 	       device self-test operation when in power state 0.
 * @dsto:      Device Self-test Options, see &enum nvme_id_ctrl_dsto.
 * @fwug:      Firmware Update Granularity indicates the granularity and
 * 	       alignment requirement of the firmware image being updated by the
 * 	       Firmware Image Download command. The value is reported in 4 KiB
 * 	       units. A value of 0h indicates no information on granularity is
 * 	       provided. A value of FFh indicates no restriction
 * @kas:       Keep Alive Support indicates the granularity of the Keep Alive
 * 	       Timer in 100 millisecond units.
 * @hctma:     Host Controlled Thermal Management Attributes, see &enum nvme_id_ctrl_hctm.
 * @mntmt:     Minimum Thermal Management Temperature indicates the minimum
 * 	       temperature, in degrees Kelvin, that the host may request in the
 * 	       Thermal Management Temperature 1 field and Thermal Management
 * 	       Temperature 2 field of a Set Features command with the Feature
 * 	       Identifier field set to #NVME_FEAT_FID_HCTM.
 * @mxtmt:     Maximum Thermal Management Temperature indicates the maximum
 * 	       temperature, in degrees Kelvin, that the host may request in the
 * 	       Thermal Management Temperature 1 field and Thermal Management
 * 	       Temperature 2 field of the Set Features command with the Feature
 * 	       Identifier set to #NVME_FEAT_FID_HCTM.
 * @sanicap:   Sanitize Capabilities, see &enum nvme_id_ctrl_sanicap
 * @hmminds:   Host Memory Buffer Minimum Descriptor Entry Size indicates the
 * 	       minimum usable size of a Host Memory Buffer Descriptor Entry in
 * 	       4 KiB units.
 * @hmmaxd:    Host Memory Maximum Descriptors Entries indicates the number of
 * 	       usable Host Memory Buffer Descriptor Entries.
 * @nsetidmax: NVM Set Identifier Maximum, defines the maximum value of a valid
 * 	       NVM Set Identifier for any controller in the NVM subsystem.
 * @endgidmax: Endurance Group Identifier Maximum, defines the maximum value of
 * 	       a valid Endurance Group Identifier for any controller in the NVM
 * 	       subsystem.
 * @anatt:     ANA Transition Time indicates the maximum amount of time, in
 * 	       seconds, for a transition between ANA states or the maximum
 * 	       amount of time, in seconds, that the controller reports the ANA
 * 	       change state.
 * @anacap:    Asymmetric Namespace Access Capabilities, see
 * 	       &enum nvme_id_ctrl_anacap.
 * @anagrpmax: ANA Group Identifier Maximum indicates the maximum value of a
 * 	       valid ANA Group Identifier for any controller in the NVM
 * 	       subsystem.
 * @nanagrpid: Number of ANA Group Identifiers indicates the number of ANA
 * 	       groups supported by this controller.
 * @pels:      Persistent Event Log Size indicates the maximum reportable size
 * 	       for the Persistent Event Log.
 * @sqes:      Submission Queue Entry Size, see &enum nvme_id_ctrl_sqes.
 * @cqes:      Completion Queue Entry Size, see &enum nvme_id_ctrl_cqes.
 * @maxcmd:    Maximum Outstanding Commands indicates the maximum number of
 * 	       commands that the controller processes at one time for a
 * 	       particular queue.
 * @nn:	       Number of Namespaces indicates the maximum value of a valid
 *	       nsid for the NVM subsystem. If the MNAN (&struct nvme_id_ctrl.mnan
 *	       field is cleared to 0h, then this field also indicates the
 *	       maximum number of namespaces supported by the NVM.  subsystem.
 * @oncs:      Optional NVM Command Support, see &enum nvme_id_ctrl_oncs.
 * @fuses:     Fused Operation Support, see &enum nvme_id_ctrl_fuses.
 * @fna:       Format NVM Attributes, see &enum nvme_id_ctrl_fna.
 * @vwc:       Volatile Write Cache, see &enum nvme_id_ctrl_vwc.
 * @awun:      Atomic Write Unit Normal indicates the size of the write
 * 	       operation guaranteed to be written atomically to the NVM across
 * 	       all namespaces with any supported namespace format during normal
 * 	       operation. This field is specified in logical blocks and is a
 * 	       0's based value.
 * @awupf:     Atomic Write Unit Power Fail indicates the size of the write
 * 	       operation guaranteed to be written atomically to the NVM across
 * 	       all namespaces with any supported namespace format during a
 * 	       power fail or error condition. This field is specified in
 * 	       logical blocks and is a 0’s based value.
 * @nvscc:     NVM Vendor Specific Command Configuration, see
 * 	       &enum nvme_id_ctrl_nvscc.
 * @nwpc:      Namespace Write Protection Capabilities, see
 * 	       &enum nvme_id_ctrl_nwpc.
 * @acwu:      Atomic Compare & Write Unit indicates the size of the write
 * 	       operation guaranteed to be written atomically to the NVM across
 * 	       all namespaces with any supported namespace format for a Compare
 * 	       and Write fused operation. This field is specified in logical
 * 	       blocks and is a 0’s based value.
 * @sgls:      SGL Support, see &enum nvme_id_ctrl_sgls
 * @mnan:      Maximum Number of Allowed Namespaces indicates the maximum
 * 	       number of namespaces supported by the NVM subsystem.
 * @subnqn:    NVM Subsystem NVMe Qualified Name, UTF-8 null terminated string
 * @ioccsz:    I/O Queue Command Capsule Supported Size, defines the maximum
 * 	       I/O command capsule size in 16 byte units.
 * @iorcsz:    I/O Queue Response Capsule Supported Size, defines the maximum
 * 	       I/O response capsule size in 16 byte units.
 * @icdoff:    In Capsule Data Offset, defines the offset where data starts
 * 	       within a capsule. This value is applicable to I/O Queues only.
 * @fcatt:     Fabrics Controller Attributes, see &enum nvme_id_ctrl_fcatt.
 * @msdbd:     Maximum SGL Data Block Descriptors indicates the maximum
 * 	       number of SGL Data Block or Keyed SGL Data Block descriptors
 * 	       that a host is allowed to place in a capsule. A value of 0h
 * 	       indicates no limit.
 * @ofcs:      Optional Fabric Commands Support, see &enum nvme_id_ctrl_ofcs.
 * @psd:       Power State Descriptors, see &struct nvme_id_psd.
 * @vs:	       Vendor Specific
 */
struct nvme_id_ctrl {
	__le16			vid;
	__le16			ssvid;
	char			sn[20];
	char			mn[40];
	char			fr[8];
	__u8			rab;
	__u8			ieee[3];
	__u8			cmic;
	__u8			mdts;
	__le16			cntlid;
	__le32			ver;
	__le32			rtd3r;
	__le32			rtd3e;
	__le32			oaes;
	__le32			ctratt;
	__le16			rrls;
	__u8			rsvd102[9];
	__u8			cntrltype;
	__u8			fguid[16];
	__le16			crdt1;
	__le16			crdt2;
	__le16			crdt3;
	__u8			rsvd134[119];
	__u8			nvmsr;
	__u8			vwci;
	__u8			mec;
	__le16			oacs;
	__u8			acl;
	__u8			aerl;
	__u8			frmw;
	__u8			lpa;
	__u8			elpe;
	__u8			npss;
	__u8			avscc;
	__u8			apsta;
	__le16			wctemp;
	__le16			cctemp;
	__le16			mtfa;
	__le32			hmpre;
	__le32			hmmin;
	__u8			tnvmcap[16];
	__u8			unvmcap[16];
	__le32			rpmbs;
	__le16			edstt;
	__u8			dsto;
	__u8			fwug;
	__le16			kas;
	__le16			hctma;
	__le16			mntmt;
	__le16			mxtmt;
	__le32			sanicap;
	__le32			hmminds;
	__le16			hmmaxd;
	__le16			nsetidmax;
	__le16			endgidmax;
	__u8			anatt;
	__u8			anacap;
	__le32			anagrpmax;
	__le32			nanagrpid;
	__le32			pels;
	__u8			rsvd356[156];
	__u8			sqes;
	__u8			cqes;
	__le16			maxcmd;
	__le32			nn;
	__le16			oncs;
	__le16			fuses;
	__u8			fna;
	__u8			vwc;
	__le16			awun;
	__le16			awupf;
	__u8			nvscc;
	__u8			nwpc;
	__le16			acwu;
	__u8			rsvd534[2];
	__le32			sgls;
	__le32			mnan;
	__u8			rsvd544[224];
	char			subnqn[NVME_NQN_LENGTH];
	__u8			rsvd1024[768];

	/* Fabrics Only */
	__le32			ioccsz;
	__le32			iorcsz;
	__le16			icdoff;
	__u8			fcatt;
	__u8			msdbd;
	__le16			ofcs;
	__u8			rsvd1806[242];

	struct nvme_id_psd	psd[32];
	__u8			vs[1024];
};

/**
 * enum nvme_id_ctrl_cmic -
 * @NVME_CTRL_CMIC_MULTI_PORT:
 * @NVME_CTRL_CMIC_MULTI_CTRL:
 * @NVME_CTRL_CMIC_MULTI_SRIOV:
 * @NVME_CTRL_CMIC_MULTI_ANA_REPORTING:
 */
enum nvme_id_ctrl_cmic {
	NVME_CTRL_CMIC_MULTI_PORT		= 1 << 0,
	NVME_CTRL_CMIC_MULTI_CTRL		= 1 << 1,
	NVME_CTRL_CMIC_MULTI_SRIOV		= 1 << 2,
	NVME_CTRL_CMIC_MULTI_ANA_REPORTING	= 1 << 3,
};

/**
 * enum nvme_id_ctrl_oaes - The typical latency in microseconds to enter Runtime D3
 * @NVME_CTRL_OAES_NA:
 * @NVME_CTRL_OAES_FA:
 * @NVME_CTRL_OAES_ANA:
 * @NVME_CTRL_OAES_PLEA:
 * @NVME_CTRL_OAES_LBAS::
 * @NVME_CTRL_OAES_EGE:
 */
enum nvme_id_ctrl_oaes {
	NVME_CTRL_OAES_NA			= 1 << 8,
	NVME_CTRL_OAES_FA			= 1 << 9,
	NVME_CTRL_OAES_ANA			= 1 << 11,
	NVME_CTRL_OAES_PLEA			= 1 << 12,
	NVME_CTRL_OAES_LBAS			= 1 << 13,
	NVME_CTRL_OAES_EGE			= 1 << 14,
};

/**
 * enum nvme_id_ctrl_ctratt -
 * @NVME_CTRL_CTRATT_128_ID:
 * @NVME_CTRL_CTRATT_NON_OP_PSP:
 * @NVME_CTRL_CTRATT_NVM_SETS:
 * @NVME_CTRL_CTRATT_READ_RECV_LVLS:
 * @NVME_CTRL_CTRATT_ENDURANCE_GROUPS:
 * @NVME_CTRL_CTRATT_PREDICTABLE_LAT:
 * @NVME_CTRL_CTRATT_TBKAS:
 * @NVME_CTRL_CTRATT_NAMESPACE_GRANULARITY:
 * @NVME_CTRL_CTRATT_SQ_ASSOCIATIONS:
 * @NVME_CTRL_CTRATT_UUID_LIST:
 */
enum nvme_id_ctrl_ctratt {
	NVME_CTRL_CTRATT_128_ID			= 1 << 0,
	NVME_CTRL_CTRATT_NON_OP_PSP		= 1 << 1,
	NVME_CTRL_CTRATT_NVM_SETS		= 1 << 2,
	NVME_CTRL_CTRATT_READ_RECV_LVLS		= 1 << 3,
	NVME_CTRL_CTRATT_ENDURANCE_GROUPS	= 1 << 4,
	NVME_CTRL_CTRATT_PREDICTABLE_LAT	= 1 << 5,
	NVME_CTRL_CTRATT_TBKAS			= 1 << 6,
	NVME_CTRL_CTRATT_NAMESPACE_GRANULARITY	= 1 << 7,
	NVME_CTRL_CTRATT_SQ_ASSOCIATIONS	= 1 << 8,
	NVME_CTRL_CTRATT_UUID_LIST		= 1 << 9,
};

/**
 * enum nvme_id_ctrl_cntrltype -
 * @NVME_CTRL_CNTRLTYPE_IO:
 * @NVME_CTRL_CNTRLTYPE_DISCOVERY:
 * @NVME_CTRL_CNTRLTYPE_ADMIN:
 */
enum nvme_id_ctrl_cntrltype {
	NVME_CTRL_CNTRLTYPE_IO			= 1,
	NVME_CTRL_CNTRLTYPE_DISCOVERY		= 2,
	NVME_CTRL_CNTRLTYPE_ADMIN		= 3,
};

/**
 * enum nvme_id_ctrl_nvmsr - This field reports information associated with the
 * 			     NVM Subsystem, see &struct nvme_id_ctrl.nvmsr.
 * @NVME_CTRL_NVMSR_NVMESD: If set, then the NVM Subsystem is part of an NVMe
 * 			    Storage Device; if cleared, then the NVM Subsystem
 * 			    is not part of an NVMe Storage Device.
 * @NVME_CTRL_NVMSR_NVMEE:  If set’, then the NVM Subsystem is part of an NVMe
 *			    Enclosure; if cleared, then the NVM Subsystem is
 *			    not part of an NVMe Enclosure.
 */
enum nvme_id_ctrl_nvmsr {
	NVME_CTRL_NVMSR_NVMESD			= 1 << 0,
	NVME_CTRL_NVMSR_NVMEE			= 1 << 1,
};

/**
 * enum nvme_id_ctrl_vwci - This field indicates information about remaining
 * 			    number of times that VPD contents are able to be
 * 			    updated using the VPD Write command, see &struct
 * 			    nvme_id_ctrl.vwci.
 * @NVME_CTRL_VWCI_VWCR:  Mask to get value of VPD Write Cycles Remaining. If
 * 			  the VPD Write Cycle Remaining Valid bit is set, then
 * 			  this field contains a value indicating the remaining
 * 			  number of times that VPD contents are able to be
 * 			  updated using the VPD Write command. If this field is
 * 			  set to 7Fh, then the remaining number of times that
 * 			  VPD contents are able to be updated using the VPD
 * 			  Write command is greater than or equal to 7Fh.
 * @NVME_CTRL_VWCI_VWCRV: VPD Write Cycle Remaining Valid. If this bit is set,
 * 			  then the VPD Write Cycle Remaining field is valid. If
 * 			  this bit is cleared, then the VPD Write Cycles
 * 			  Remaining field is invalid and cleared to 0h.
 */
enum nvme_id_ctrl_vwci {
	NVME_CTRL_VWCI_VWCR			= 0x7f << 0,
	NVME_CTRL_VWCI_VWCRV			= 1 << 7,
};

/**
 * enum nvme_id_ctrl_mec - Flags indicatings the capabilities of the Management
 * 			   Endpoint in the Controller, &struct nvme_id_ctrl.mec.
 * @NVME_CTRL_MEC_SMBUSME: If set, then the NVM Subsystem contains a Management
 * 			   Endpoint on an SMBus/I2C port.
 * @NVME_CTRL_MEC_PCIEME:  If set, then the NVM Subsystem contains a Management
 * 			   Endpoint on a PCIe port.
 */
enum nvme_id_ctrl_mec {
	NVME_CTRL_MEC_SMBUSME			= 1 << 0,
	NVME_CTRL_MEC_PCIEME			= 1 << 1,
};

/**
 * enum nvme_id_ctrl_oacs - Flags indicating the optional Admin commands and
 * 			    features supported by the controller, see
 * 			    &struct nvme_id_ctrl.oacs.
 * @NVME_CTRL_OACS_SECURITY:   If set, then the controller supports the
 * 			       Security Send and Security Receive commands.
 * @NVME_CTRL_OACS_FORMAT:     If set then the controller supports the Format
 * 			       NVM command.
 * @NVME_CTRL_OACS_FW:	       If set, then the controller supports the
 * 			       Firmware Commit and Firmware Image Download commands.
 * @NVME_CTRL_OACS_NS_MGMT:    If set, then the controller supports the
 * 			       Namespace Management capability
 * @NVME_CTRL_OACS_SELF_TEST:  If set, then the controller supports the Device
 * 			       Self-test command.
 * @NVME_CTRL_OACS_DIRECTIVES: If set, then the controller supports Directives
 *			       and the Directive Send and Directive Receive
 *			       commands.
 * @NVME_CTRL_OACS_NVME_MI:    If set, then the controller supports the NVMe-MI
 * 			       Send and NVMe-MI Receive commands.
 * @NVME_CTRL_OACS_VIRT_MGMT:  If set, then the controller supports the
 * 			       Virtualization Management command.
 * @NVME_CTRL_OACS_DBBUF_CFG:  If set, then the controller supports the
 * 			       Doorbell Buffer Config command.
 * @NVME_CTRL_OACS_LBA_STATUS: If set, then the controller supports the Get LBA
 * 			       Status capability.
 */
enum nvme_id_ctrl_oacs {
	NVME_CTRL_OACS_SECURITY			= 1 << 0,
	NVME_CTRL_OACS_FORMAT			= 1 << 1,
	NVME_CTRL_OACS_FW			= 1 << 2,
	NVME_CTRL_OACS_NS_MGMT			= 1 << 3,
	NVME_CTRL_OACS_SELF_TEST		= 1 << 4,
	NVME_CTRL_OACS_DIRECTIVES		= 1 << 5,
	NVME_CTRL_OACS_NVME_MI			= 1 << 6,
	NVME_CTRL_OACS_VIRT_MGMT		= 1 << 7,
	NVME_CTRL_OACS_DBBUF_CFG		= 1 << 8,
	NVME_CTRL_OACS_LBA_STATUS		= 1 << 9,
};

/**
 * enum nvme_id_ctrl_frmw - Flags and values indicates capabilities regarding
 * 			    firmware updates from &struct nvme_id_ctrl.frmw.
 * @NVME_CTRL_FRMW_1ST_RO:	    If set, the first firmware slot is readonly
 * @NVME_CTRL_FRMW_NR_SLOTS:	    Mask to get the value of the number of
 * 				    firmware slots that the controller supports.
 * @NVME_CTRL_FRMW_FW_ACT_NO_RESET: If set, the controller supports firmware
 * 				    activation without a reset.
 */
enum nvme_id_ctrl_frmw {
	NVME_CTRL_FRMW_1ST_RO			= 1 << 0,
	NVME_CTRL_FRMW_NR_SLOTS			= 3 << 1,
	NVME_CTRL_FRMW_FW_ACT_NO_RESET		= 1 << 4,
};

/**
 * enum nvme_id_ctrl_lpa - Flags indicating optional attributes for log pages
 * 			   that are accessed via the Get Log Page command.
 * @NVME_CTRL_LPA_SMART_PER_NS:
 * @NVME_CTRL_LPA_CMD_EFFECTS:
 * @NVME_CTRL_LPA_EXTENDED:
 * @NVME_CTRL_LPA_TELEMETRY:
 * @NVME_CTRL_LPA_PERSETENT_EVENT:
 */
enum nvme_id_ctrl_lpa {
	NVME_CTRL_LPA_SMART_PER_NS		= 1 << 0,
	NVME_CTRL_LPA_CMD_EFFECTS		= 1 << 1,
	NVME_CTRL_LPA_EXTENDED			= 1 << 2,
	NVME_CTRL_LPA_TELEMETRY			= 1 << 3,
	NVME_CTRL_LPA_PERSETENT_EVENT		= 1 << 4,
};

/**
 * enum nvme_id_ctrl_avscc - Flags indicating the configuration settings for
 * 			     Admin Vendor Specific command handling.
 * @NVME_CTRL_AVSCC_AVS: If set, all Admin Vendor Specific Commands use the
 * 			 optional vendor specific command format with NDT and
 * 			 NDM fields.
 */
enum nvme_id_ctrl_avscc {
	NVME_CTRL_AVSCC_AVS			= 1 << 0,
};

/**
 * enum nvme_id_ctrl_apsta - Flags indicating the attributes of the autonomous
 * 			     power state transition feature.
 * @NVME_CTRL_APSTA_APST: If set, then the controller supports autonomous power
 * 			  state transitions.
 */
enum nvme_id_ctrl_apsta {
	NVME_CTRL_APSTA_APST			= 1 << 0,
};

/**
 * enum nvme_id_ctrl_rpmbs - This field indicates if the controller supports
 * 			     one or more Replay Protected Memory Blocks, from
 * 			     &struct nvme_id_ctrl.rpmbs.
 * @NVME_CTRL_RPMBS_NR_UNITS:	 Mask to get the value of the Number of RPMB Units
 * @NVME_CTRL_RPMBS_AUTH_METHOD: Mask to get the value of the Authentication Method
 * @NVME_CTRL_RPMBS_TOTAL_SIZE:  Mask to get the value of Total Size
 * @NVME_CTRL_RPMBS_ACCESS_SIZE: Mask to get the value of Access Size
 */
enum nvme_id_ctrl_rpmbs {
	NVME_CTRL_RPMBS_NR_UNITS		= 7 << 0,
	NVME_CTRL_RPMBS_AUTH_METHOD		= 7 << 3,
	NVME_CTRL_RPMBS_TOTAL_SIZE		= 0xff << 16,
	NVME_CTRL_RPMBS_ACCESS_SIZE		= 0xff << 24,
};

/**
 * enum nvme_id_ctrl_dsto - Flags indicating the optional Device Self-test
 * 			    command or operation behaviors supported by the
 * 			    controller or NVM subsystem.
 * @NVME_CTRL_DSTO_ONE_DST: If set,  then the NVM subsystem supports only one
 * 			    device self-test operation in progress at a time.
 */
enum nvme_id_ctrl_dsto {
	NVME_CTRL_DSTO_ONE_DST			= 1 << 0,
};

/**
 * enum nvme_id_ctrl_hctm - Flags indicate the attributes of the host
 * 			    controlled thermal management feature
 * @NVME_CTRL_HCTMA_HCTM: then the controller supports host controlled thermal
 * 			  management, and the Set Features command and Get
 * 			  Features command with the Feature Identifier field
 * 			  set to %NVME_FEAT_FID_HCTM.
 */
enum nvme_id_ctrl_hctm {
	NVME_CTRL_HCTMA_HCTM			= 1 << 0,
};

/**
 * enum nvme_id_ctrl_sanicap - Indicates attributes for sanitize operations.
 * @NVME_CTRL_SANICAP_CES:     Crypto Erase Support. If set, then the
 * 			       controller supports the Crypto Erase sanitize operation.
 * @NVME_CTRL_SANICAP_BES:     Block Erase Support. If set, then the controller
 * 			       supports the Block Erase sanitize operation.
 * @NVME_CTRL_SANICAP_OWS:     Overwrite Support. If set, then the controller
 * 			       supports the Overwrite sanitize operation.
 * @NVME_CTRL_SANICAP_NDI:     No-Deallocate Inhibited. If set and the No-
 * 			       Deallocate Response Mode bit is set, then the
 * 			       controller deallocates after the sanitize
 * 			       operation even if the No-Deallocate After
 * 			       Sanitize bit is set in a Sanitize command.
 * @NVME_CTRL_SANICAP_NODMMAS: No-Deallocate Modifies Media After Sanitize,
 * 			       mask to extract value.
 */
enum nvme_id_ctrl_sanicap {
	NVME_CTRL_SANICAP_CES			= 1 << 0,
	NVME_CTRL_SANICAP_BES			= 1 << 1,
	NVME_CTRL_SANICAP_OWS			= 1 << 2,
	NVME_CTRL_SANICAP_NDI			= 1 << 29,
	NVME_CTRL_SANICAP_NODMMAS		= 3 << 30,
};

/**
 * enum nvme_id_ctrl_anacap - This field indicates the capabilities associated
 * 			      with Asymmetric Namespace Access Reporting.
 * @NVME_CTRL_ANACAP_OPT:             If set, then the controller is able to
 * 				      report ANA Optimized state.
 * @NVME_CTRL_ANACAP_NON_OPT:         If set, then the controller is able to
 * 				      report ANA Non-Optimized state.
 * @NVME_CTRL_ANACAP_INACCESSIBLE:    If set, then the controller is able to
 * 				      report ANA Inaccessible state.
 * @NVME_CTRL_ANACAP_PERSISTENT_LOSS: If set, then the controller is able to
 * 				      report ANA Persistent Loss state.
 * @NVME_CTRL_ANACAP_CHANGE:          If set, then the controller is able to
 * 				      report ANA Change state.
 * @NVME_CTRL_ANACAP_GRPID_NO_CHG:    If set, then the ANAGRPID field in the
 * 				      Identify Namespace data structure
 * 				      (&struct nvme_id_ns.anagrpid), does not
 * 				      change while the namespace is attached to
 * 				      any controller.
 * @NVME_CTRL_ANACAP_GRPID_MGMT:      If set, then the controller supports a
 * 				      non-zero value in the ANAGRPID field of
 * 				      the Namespace Management command.
 */
enum nvme_id_ctrl_anacap {
	NVME_CTRL_ANACAP_OPT			= 1 << 0,
	NVME_CTRL_ANACAP_NON_OPT		= 1 << 1,
	NVME_CTRL_ANACAP_INACCESSIBLE		= 1 << 2,
	NVME_CTRL_ANACAP_PERSISTENT_LOSS	= 1 << 3,
	NVME_CTRL_ANACAP_CHANGE			= 1 << 4,
	NVME_CTRL_ANACAP_GRPID_NO_CHG		= 1 << 6,
	NVME_CTRL_ANACAP_GRPID_MGMT		= 1 << 7,
};

/**
 * enum nvme_id_ctrl_sqes - Defines the required and maximum Submission Queue
 * 			    entry size when using the NVM Command Set.
 * @NVME_CTRL_SQES_MIN: Mask to get the value of the required Submission Queue
 * 			Entry size when using the NVM Command Set.
 * @NVME_CTRL_SQES_MAX: Mask to get the value of the maximum Submission Queue
 * 			entry size when using the NVM Command Set.
 */
enum nvme_id_ctrl_sqes {
	NVME_CTRL_SQES_MIN			= 0xf << 0,
	NVME_CTRL_SQES_MAX			= 0xf << 4,
};

/**
 * enum nvme_id_ctrl_cqes - Defines the required and maximum Completion Queue
 * 			    entry size when using the NVM Command Set.
 * @NVME_CTRL_CQES_MIN: Mask to get the value of the required Completion Queue
 * 			Entry size when using the NVM Command Set.
 * @NVME_CTRL_CQES_MAX: Mask to get the value of the maximum Completion Queue
 * 			entry size when using the NVM Command Set.
 */
enum {
	NVME_CTRL_CQES_MIN			= 0xf << 0,
	NVME_CTRL_CQES_MAX			= 0xf << 4,
};

/**
 * enum nvme_id_ctrl_oncs - This field indicates the optional NVM commands and
 * 			    features supported by the controller.
 * @NVME_CTRL_ONCS_COMPARE:		If set, then the controller supports
 * 					the Compare command.
 * @NVME_CTRL_ONCS_WRITE_UNCORRECTABLE:	If set, then the controller supports
 * 					the Write Uncorrectable command.
 * @NVME_CTRL_ONCS_DSM:			If set, then the controller supports
 * 					the Dataset Management command.
 * @NVME_CTRL_ONCS_WRITE_ZEROES:	If set, then the controller supports
 * 					the Write Zeroes command.
 * @NVME_CTRL_ONCS_SAVE_FEATURES:	If set, then the controller supports
 * 					the Save field set to a non-zero value
 * 					in the Set Features command and the
 * 					Select field set to a non-zero value in
 * 					the Get Features command.
 * @NVME_CTRL_ONCS_RESERVATIONS:	If set, then the controller supports
 * 					reservations.
 * @NVME_CTRL_ONCS_TIMESTAMP:		If set, then the controller supports
 * 					the Timestamp feature.
 * @NVME_CTRL_ONCS_VERIFY:		If set, then the controller supports
 * 					the Verify command.
 */
enum nvme_id_ctrl_oncs {
	NVME_CTRL_ONCS_COMPARE			= 1 << 0,
	NVME_CTRL_ONCS_WRITE_UNCORRECTABLE	= 1 << 1,
	NVME_CTRL_ONCS_DSM			= 1 << 2,
	NVME_CTRL_ONCS_WRITE_ZEROES		= 1 << 3,
	NVME_CTRL_ONCS_SAVE_FEATURES		= 1 << 4,
	NVME_CTRL_ONCS_RESERVATIONS		= 1 << 5,
	NVME_CTRL_ONCS_TIMESTAMP		= 1 << 6,
	NVME_CTRL_ONCS_VERIFY			= 1 << 7,
};

/**
 * enum nvme_id_ctrl_fuses - This field indicates the fused operations that the
 * 			     controller supports.
 * @NVME_CTRL_FUSES_COMPARE_AND_WRITE: If set, then the controller supports the
 * 				       Compare and Write fused operation.
 */
enum nvme_id_ctrl_fuses {
	NVME_CTRL_FUSES_COMPARE_AND_WRITE	= 1 << 0,
};

/**
 * enum nvme_id_ctrl_fna - This field indicates attributes for the Format NVM
 * 			   command.
 * @NVME_CTRL_FNA_FMT_ALL_NAMESPACES: If set, then all namespaces in an NVM
 * 				      subsystem shall be configured with the
 * 				      same attributes and a format (excluding
 * 				      secure erase) of any namespace results in
 * 				      a format of all namespaces in an NVM
 * 				      subsystem. If cleared, then the
 * 				      controller supports format on a per
 * 				      namespace basis.
 * @NVME_CTRL_FNA_SEC_ALL_NAMESPACES: If set, then any secure erase performed
 * 				      as part of a format operation results in
 * 				      a secure erase of all namespaces in the
 * 				      NVM subsystem. If cleared, then any
 * 				      secure erase performed as part of a
 * 				      format results in a secure erase of the
 * 				      particular namespace specified.
 * @NVME_CTRL_FNA_CRYPTO_ERASE:       If set, then cryptographic erase is
 * 				      supported. If cleared, then cryptographic
 * 				      erase is not supported.
 */
enum nvme_id_ctrl_fna {
	NVME_CTRL_FNA_FMT_ALL_NAMESPACES	= 1 << 0,
	NVME_CTRL_FNA_SEC_ALL_NAMESPACES	= 1 << 1,
	NVME_CTRL_FNA_CRYPTO_ERASE		= 1 << 2,
};

/**
 * enum nvme_id_ctrl_vwc -
 * @NVME_CTRL_VWC_PRESENT: If set, indicates a volatile write cache is present.
 * 			   If a volatile write cache is present, then the host
 * 			   controls whether the volatile write cache is enabled
 * 			   with a Set Features command specifying the value
 * 			   %NVME_FEAT_FID_VOLATILE_WC.
 * @NVME_CTRL_VWC_FLUSH:   Mask to get the value of the flush command behavior.
 */
enum nvme_id_ctrl_vwc {
	NVME_CTRL_VWC_PRESENT			= 1 << 0,
	NVME_CTRL_VWC_FLUSH			= 3 << 1,
};

/**
 * enum nvme_id_ctrl_nvscc - This field indicates the configuration settings
 * 			     for NVM Vendor Specific command handling.
 * @NVME_CTRL_NVSCC_FMT: If set, all NVM Vendor Specific Commands use the
 * 			 format format with NDT and NDM fields.
 */
enum nvme_id_ctrl_nvscc {
	NVME_CTRL_NVSCC_FMT			= 1 << 0,
};

/**
 * enum nvme_id_ctrl_nwpc - This field indicates the optional namespace write
 * 			    protection capabilities supported by the
 * 			    controller.
 * @NVME_CTRL_NWPC_WRITE_PROTECT:	     If set, then the controller shall
 * 					      support the No Write Protect and
 * 					      Write Protect namespace write
 * 					      protection states and may support
 * 					      the Write Protect Until Power
 * 					      Cycle state and Permanent Write
 * 					      Protect namespace write
 * 					      protection states.
 * @NVME_CTRL_NWPC_WRITE_PROTECT_POWER_CYCLE: If set, then the controller
 * 					      supports the Write Protect Until
 * 					      Power Cycle state.
 * @NVME_CTRL_NWPC_WRITE_PROTECT_PERMANENT:   If set, then the controller
 * 					      supports the Permanent Write
 * 					      Protect state.
 */
enum nvme_id_ctrl_nwpc {
	NVME_CTRL_NWPC_WRITE_PROTECT		= 1 << 0,
	NVME_CTRL_NWPC_WRITE_PROTECT_POWER_CYCLE= 1 << 1,
	NVME_CTRL_NWPC_WRITE_PROTECT_PERMANENT	= 1 << 2,
};

/**
 * enum nvme_id_ctrl_sgls - This field indicates if SGLs are supported for the
 * 			    NVM Command Set and the particular SGL types supported.
 * @NVME_CTRL_SGLS_SUPPORTED:
 * @NVME_CTRL_SGLS_KEYED:
 * @NVME_CTRL_SGLS_BIT_BUCKET:
 * @NVME_CTRL_SGLS_MPTR_BYTE_ALIGNED:
 * @NVME_CTRL_SGLS_OVERSIZE:
 * @NVME_CTRL_SGLS_MPTR_SGL:
 * @NVME_CTRL_SGLS_OFFSET:
 * @NVME_CTRL_SGLS_TPORT:
 */
enum nvme_id_ctrl_sgls {
	NVME_CTRL_SGLS_SUPPORTED		= 3 << 0,
	NVME_CTRL_SGLS_KEYED			= 1 << 2,
	NVME_CTRL_SGLS_BIT_BUCKET		= 1 << 16,
	NVME_CTRL_SGLS_MPTR_BYTE_ALIGNED	= 1 << 17,
	NVME_CTRL_SGLS_OVERSIZE			= 1 << 18,
	NVME_CTRL_SGLS_MPTR_SGL			= 1 << 19,
	NVME_CTRL_SGLS_OFFSET			= 1 << 20,
	NVME_CTRL_SGLS_TPORT			= 1 << 21,
};

/**
 * enum nvme_id_ctrl_fcatt - This field indicates attributes of the controller
 * 			     that are specific to NVMe over Fabrics.
 * @NVME_CTRL_FCATT_DYNAMIC: If cleared, then the NVM subsystem uses a dynamic
 * 			     controller model. If set, then the NVM subsystem
 * 			     uses a static controller model.
 */
enum nvme_id_ctrl_fcatt {
	NVME_CTRL_FCATT_DYNAMIC			= 1 << 0,
};

/**
 * enum nvme_id_ctrl_ofcs - Indicate whether the controller supports optional
 * 			    fabric commands.
 * @NVME_CTRL_OFCS_DISCONNECT: If set, then the controller supports the
 * 			       Disconnect command and deletion of individual
 * 			       I/O Queues.
 */
enum nvme_id_ctrl_ofcs {
	NVME_CTRL_OFCS_DISCONNECT		= 1 << 0,
};

/**
 * struct nvme_lbaf - LBA Format Data Structure
 * @ms: Metadata Size indicates the number of metadata bytes provided per LBA
 * 	based on the LBA Data Size indicated.
 * @ds:	LBA Data Size indicates the LBA data size supported, reported as a
 * 	power of two.
 * @rp:	Relative Performance, see &enum nvme_lbaf_rp.
 */
struct nvme_lbaf {
	__le16			ms;
	__u8			ds;
	__u8			rp;
};

/**
 * enum nvme_lbaf_rp - This field indicates the relative performance of the LBA
 * 		       format indicated relative to other LBA formats supported
 * 		       by the controller.
 * @NVME_LBAF_RP_BEST:	   Best performance
 * @NVME_LBAF_RP_BETTER:   Better performance
 * @NVME_LBAF_RP_GOOD:	   Good performance
 * @NVME_LBAF_RP_DEGRADED: Degraded performance
 * @NVME_LBAF_RP_MASK:	   Mask to get the relative performance value from the
 * 			   field
 */
enum nvme_lbaf_rp {
	NVME_LBAF_RP_BEST	= 0,
	NVME_LBAF_RP_BETTER	= 1,
	NVME_LBAF_RP_GOOD	= 2,
	NVME_LBAF_RP_DEGRADED	= 3,
	NVME_LBAF_RP_MASK	= 3,
};

/**
 * struct nvme_id_ns - Identify Namespace data structure
 * @nsze:     Namespace Size indicates the total size of the namespace in
 * 	      logical blocks. The number of logical blocks is based on the
 * 	      formatted LBA size.
 * @ncap:     Namespace Capacity indicates the maximum number of logical blocks
 * 	      that may be allocated in the namespace at any point in time. The
 * 	      number of logical blocks is based on the formatted LBA size.
 * @nuse:     Namespace Utilization indicates the current number of logical
 * 	      blocks allocated in the namespace. This field is smaller than or
 * 	      equal to the Namespace Capacity. The number of logical blocks is
 * 	      based on the formatted LBA size.
 * @nsfeat:   Namespace Features, see &enum nvme_id_nsfeat.
 * @nlbaf:    Number of LBA Formats defines the number of supported LBA data
 * 	      size and metadata size combinations supported by the namespace
 * 	      and the highest possible index to &struct nvme_id_ns.labf.
 * @flbas:    Formatted LBA Size, see &enum nvme_id_ns_flbas.
 * @mc:       Metadata Capabilities, see &enum nvme_id_ns_mc.
 * @dpc:      End-to-end Data Protection Capabilities, see
 * 	      &enum nvme_id_ns_dpc.
 * @dps:      End-to-end Data Protection Type Settings, see
 * 	      &enum nvme_id_ns_dps.
 * @nmic:     Namespace Multi-path I/O and Namespace Sharing Capabilities, see
 * 	      &enum nvme_id_ns_nmic.
 * @rescap:   Reservation Capabilities, see &enum nvme_id_ns_rescap.
 * @fpi:      Format Progress Indicator, see &enum nvme_nd_ns_fpi.
 * @dlfeat:   Deallocate Logical Block Features, see &enum nvme_id_ns_dlfeat.
 * @nawun:    Namespace Atomic Write Unit Normal indicates the
 * 	      namespace specific size of the write operation guaranteed to be
 * 	      written atomically to the NVM during normal operation.
 * @nawupf:   Namespace Atomic Write Unit Power Fail indicates the
 * 	      namespace specific size of the write operation guaranteed to be
 * 	      written atomically to the NVM during a power fail or error
 * 	      condition.
 * @nacwu:    Namespace Atomic Compare & Write Unit indicates the namespace
 * 	      specific size of the write operation guaranteed to be written
 * 	      atomically to the NVM for a Compare and Write fused command.
 * @nabsn:    Namespace Atomic Boundary Size Normal indicates the atomic
 * 	      boundary size for this namespace for the NAWUN value. This field
 * 	      is specified in logical blocks.
 * @nabo:     Namespace Atomic Boundary Offset indicates the LBA on this
 * 	      namespace where the first atomic boundary starts.
 * @nabspf:   Namespace Atomic Boundary Size Power Fail indicates the atomic
 * 	      boundary size for this namespace specific to the Namespace Atomic
 * 	      Write Unit Power Fail value. This field is specified in logical
 * 	      blocks.
 * @noiob:    Namespace Optimal I/O Boundary indicates the optimal I/O boundary
 * 	      for this namespace. This field is specified in logical blocks.
 * 	      The host should construct Read and Write commands that do not
 * 	      cross the I/O boundary to achieve optimal performance.
 * @nvmcap:   NVM Capacity indicates the total size of the NVM allocated to
 * 	      this namespace. The value is in bytes.
 * @npwg:     Namespace Preferred Write Granularity indicates the smallest
 * 	      recommended write granularity in logical blocks for this
 * 	      namespace. This is a 0's based value.
 * @npwa:     Namespace Preferred Write Alignment indicates the recommended
 * 	      write alignment in logical blocks for this namespace. This is a
 * 	      0's based value.
 * @npdg:     Namespace Preferred Deallocate Granularity indicates the
 * 	      recommended granularity in logical blocks for the Dataset
 * 	      Management command with the Attribute - Deallocate bit.
 * @npda:     Namespace Preferred Deallocate Alignment indicates the
 * 	      recommended alignment in logical blocks for the Dataset
 * 	      Management command with the Attribute - Deallocate bit
 * @nows:     Namespace Optimal Write Size indicates the size in logical blocks
 * 	      for optimal write performance for this namespace. This is a 0's
 * 	      based value.
 * @anagrpid: ANA Group Identifier indicates the ANA Group Identifier of the
 * 	      ANA group of which the namespace is a member.
 * @nsattr:   Namespace Attributes, see &enum nvme_id_ns_attr.
 * @nvmsetid: NVM Set Identifier indicates the NVM Set with which this
 * 	      namespace is associated.
 * @endgid:   Endurance Group Identifier indicates the Endurance Group with
 * 	      which this namespace is associated.
 * @nguid:    Namespace Globally Unique Identifier contains a 128-bit value
 * 	      that is globally unique and assigned to the namespace when the
 * 	      namespace is created. This field remains fixed throughout the
 * 	      life of the namespace and is preserved across namespace and
 * 	      controller operations
 * @eui64:    IEEE Extended Unique Identifier contains a 64-bit IEEE Extended
 *	      Unique Identifier (EUI-64) that is globally unique and assigned
 *	      to the namespace when the namespace is created. This field
 *	      remains fixed throughout the life of the namespace and is
 *	      preserved across namespace and controller operations
 * @lbaf:     LBA Format, see &struct nvme_lbaf.
 * @vs:	      Vendor Specific
 */
struct nvme_id_ns {
	__le64			nsze;
	__le64			ncap;
	__le64			nuse;
	__u8			nsfeat;
	__u8			nlbaf;
	__u8			flbas;
	__u8			mc;
	__u8			dpc;
	__u8			dps;
	__u8			nmic;
	__u8			rescap;
	__u8			fpi;
	__u8			dlfeat;
	__le16			nawun;
	__le16			nawupf;
	__le16			nacwu;
	__le16			nabsn;
	__le16			nabo;
	__le16			nabspf;
	__le16			noiob;
	__u8			nvmcap[16];
	__le16			npwg;
	__le16			npwa;
	__le16			npdg;
	__le16			npda;
	__le16			nows;
	__u8			rsvd74[18];
	__le32			anagrpid;
	__u8			rsvd96[3];
	__u8			nsattr;
	__le16			nvmsetid;
	__le16			endgid;
	__u8			nguid[16];
	__u8			eui64[8];
	struct nvme_lbaf	lbaf[16];
	__u8			rsvd192[192];
	__u8			vs[3712];
};

/**
 * enum nvme_id_nsfeat - This field defines features of the namespace.
 * @NVME_NS_FEAT_THIN:	   If set, indicates that the namespace supports thin
 * 			   provisioning. Specifically, the Namespace Capacity
 * 			   reported may be less than the Namespace Size.
 * @NVME_NS_FEAT_NATOMIC:  If set, indicates that the fields NAWUN, NAWUPF, and
 * 			   NACWU are defined for this namespace and should be
 * 			   used by the host for this namespace instead of the
 * 			   AWUN, AWUPF, and ACWU fields in the Identify
 * 			   Controller data structure.
 * @NVME_NS_FEAT_DULBE:	   If set, indicates that the controller supports the
 * 			   Deallocated or Unwritten Logical Block error for
 * 			   this namespace.  @NVME_NS_FEAT_ID_REUSE: If set,
 * 			   indicates that the value in the NGUID field for this
 * 			   namespace, if non- zero, is never reused by the
 * 			   controller and that the value in the EUI64 field for
 * 			   this namespace, if non-zero, is never reused by the
 * 			   controller.
 * @NVME_NS_FEAT_IO_OPT:   If set, indicates that the fields NPWG, NPWA, NPDG,
 * 			   NPDA, and NOWS are defined for this namespace and
 * 			   should be used by the host for I/O optimization
 */
enum nvme_id_nsfeat {
	NVME_NS_FEAT_THIN		= 1 << 0,
	NVME_NS_FEAT_NATOMIC		= 1 << 1,
	NVME_NS_FEAT_DULBE		= 1 << 2,
	NVME_NS_FEAT_ID_REUSE		= 1 << 3,
	NVME_NS_FEAT_IO_OPT		= 1 << 4,
};

/**
 * enum nvme_id_ns_flbas - This field indicates the LBA data size & metadata
 * 			   size combination that the namespace has been
 * 			   formatted with
 * @NVME_NS_FLBAS_LBA_MASK: Mask to get the index of one of the 16 supported
 * 			    LBA Formats indicated in &struct nvme_id_ns.lbaf.
 * @NVME_NS_FLBAS_META_EXT: Applicable only if format contains metadata. If
 * 			    this bit is set, indicates that the metadata is
 * 			    transferred at the end of the data LBA, creating an
 * 			    extended data LBA. If cleared, indicates that all
 * 			    of the metadata for a command is transferred as a
 * 			    separate contiguous buffer of data.
 */
enum nvme_id_ns_flbas {
	NVME_NS_FLBAS_LBA_MASK		= 15 << 0,
	NVME_NS_FLBAS_META_EXT		= 1 << 4,
};

/**
 * enum nvme_id_ns_mc - This field indicates the capabilities for metadata.
 * @NVME_NS_MC_EXTENDED: If set, indicates the namespace supports the metadata
 * 			 being transferred as part of a separate buffer that is
 * 			 specified in the Metadata Pointer.
 * @NVME_NS_MC_SEPARATE: If set, indicates that the namespace supports the
 * 			 metadata being transferred as part of an extended data LBA.
 */
enum nvme_id_ns_mc {
	NVME_NS_MC_EXTENDED		= 1 << 0,
	NVME_NS_MC_SEPARATE		= 1 << 1,
};

/**
 * enum nvme_id_ns_dpc - This field indicates the capabilities for the
 * 			 end-to-end data protection feature.
 * @NVME_NS_DPC_PI_TYPE1: If set, indicates that the namespace supports
 * 			  Protection Information Type 1.
 * @NVME_NS_DPC_PI_TYPE2: If set, indicates that the namespace supports
 * 			  Protection Information Type 2.
 * @NVME_NS_DPC_PI_TYPE3: If set, indicates that the namespace supports
 * 			  Protection Information Type 3.
 * @NVME_NS_DPC_PI_FIRST: If set, indicates that the namespace supports
 * 			  protection information transferred as the first eight
 * 			  bytes of metadata.
 * @NVME_NS_DPC_PI_LAST:  If set, indicates that the namespace supports
 * 			  protection information transferred as the last eight
 * 			  bytes of metadata.
 */
enum nvme_id_ns_dpc {
	NVME_NS_DPC_PI_TYPE1		= 1 << 0,
	NVME_NS_DPC_PI_TYPE2		= 1 << 1,
	NVME_NS_DPC_PI_TYPE3		= 1 << 2,
	NVME_NS_DPC_PI_FIRST		= 1 << 3,
	NVME_NS_DPC_PI_LAST		= 1 << 4,
};

/**
 * enum nvme_id_ns_dps - This field indicates the Type settings for the
 * 			 end-to-end data protection feature.
 * @NVME_NS_DPS_PI_NONE:  Protection information is not enabled
 * @NVME_NS_DPS_PI_TYPE1: Protection information is enabled, Type 1
 * @NVME_NS_DPS_PI_TYPE2: Protection information is enabled, Type 2
 * @NVME_NS_DPS_PI_TYPE3: Protection information is enabled, Type 3
 * @NVME_NS_DPS_PI_MASK:  Mask to get the value of the PI type
 * @NVME_NS_DPS_PI_FIRST: If set, indicates that the protection information, if
 * 			  enabled, is transferred as the first eight bytes of
 * 			  metadata.
 */
enum nvme_id_ns_dps {
	NVME_NS_DPS_PI_NONE		= 0,
	NVME_NS_DPS_PI_TYPE1		= 1,
	NVME_NS_DPS_PI_TYPE2		= 2,
	NVME_NS_DPS_PI_TYPE3		= 3,
	NVME_NS_DPS_PI_MASK		= 7 << 0,
	NVME_NS_DPS_PI_FIRST		= 1 << 3,
};

/**
 * enum nvme_id_ns_nmic - This field specifies multi-path I/O and namespace
 * 			  sharing capabilities of the namespace.
 * @NVME_NS_NMIC_SHARED: If set, then the namespace may be attached to two or
 * 			 more controllers in the NVM subsystem concurrently
 */
enum nvme_id_ns_nmic {
	NVME_NS_NMIC_SHARED		= 1 << 0,
};

/**
 * enum nvme_id_ns_rescap - This field indicates the reservation capabilities
 * 			    of the namespace.
 * @NVME_NS_RESCAP_PTPL:   If set, indicates that the namespace supports the
 * 			   Persist Through Power Loss capability.
 * @NVME_NS_RESCAP_WE:     If set, indicates that the namespace supports the
 * 			   Write Exclusive reservation type.
 * @NVME_NS_RESCAP_EA:     If set, indicates that the namespace supports the
 * 			   Exclusive Access reservation type.
 * @NVME_NS_RESCAP_WERO:   If set, indicates that the namespace supports the
 * 			   Write Exclusive - Registrants Only reservation type.
 * @NVME_NS_RESCAP_EARO:   If set, indicates that the namespace supports the
 * 			   Exclusive Access - Registrants Only reservation type.
 * @NVME_NS_RESCAP_WEAR:   If set, indicates that the namespace supports the
 * 			   Write Exclusive - All Registrants reservation type.
 * @NVME_NS_RESCAP_EAAR:   If set, indicates that the namespace supports the
 * 			   Exclusive Access - All Registrants reservation type.
 * @NVME_NS_RESCAP_IEK_13: If set, indicates that Ignore Existing Key is used
 * 			   as defined in revision 1.3 or later of this specification.
 */
enum nvme_id_ns_rescap {
	NVME_NS_RESCAP_PTPL		= 1 << 0,
	NVME_NS_RESCAP_WE		= 1 << 1,
	NVME_NS_RESCAP_EA		= 1 << 2,
	NVME_NS_RESCAP_WERO		= 1 << 3,
	NVME_NS_RESCAP_EARO		= 1 << 4,
	NVME_NS_RESCAP_WEAR		= 1 << 5,
	NVME_NS_RESCAP_EAAR		= 1 << 6,
	NVME_NS_RESCAP_IEK_13		= 1 << 7,
};

/**
 * enum nvme_nd_ns_fpi - If a format operation is in progress, this field
 * 			 indicates the percentage of the namespace that remains
 * 			 to be formatted.
 * @NVME_NS_FPI_REMAINING: Mask to get the format percent remaining value
 * @NVME_NS_FPI_SUPPORTED: If set, indicates that the namespace supports the
 * 			   Format Progress Indicator defined for the field.
 */
enum nvme_nd_ns_fpi {
	NVME_NS_FPI_REMAINING		= 0x7f << 0,
	NVME_NS_FPI_SUPPORTED		= 1 << 7,
};

/**
 * enum nvme_id_ns_dlfeat - This field indicates information about features
 * 			    that affect deallocating logical blocks for this
 * 			    namespace.
 * @NVME_NS_DLFEAT_RB:           Mask to get the value of the read behavior
 * @NVME_NS_DLFEAT_RB_NR:        Read behvaior is not reported
 * @NVME_NS_DLFEAT_RB_ALL_0S:    A deallocated logical block returns all bytes
 * cleared to 0h.
 * @NVME_NS_DLFEAT_RB_ALL_FS:    A deallocated logical block returns all bytes
 * 				 set to FFh.
 * @NVME_NS_DLFEAT_WRITE_ZEROES: If set, indicates that the controller supports
 * 				 the Deallocate bit in the Write Zeroes command
 * 				 for this namespace.
 * @NVME_NS_DLFEAT_CRC_GUARD:    If set, indicates that the Guard field for
 * 				 deallocated logical blocks that contain
 * 				 protection information is set to the CRC for
 * 				 the value read from the deallocated logical
 * 				 block and its metadata
 */
enum nvme_id_ns_dlfeat {
	NVME_NS_DLFEAT_RB		= 7 << 0,
	NVME_NS_DLFEAT_RB_NR		= 0,
	NVME_NS_DLFEAT_RB_ALL_0S	= 1,
	NVME_NS_DLFEAT_RB_ALL_FS	= 2,
	NVME_NS_DLFEAT_WRITE_ZEROES	= 1 << 3,
	NVME_NS_DLFEAT_CRC_GUARD	= 1 << 4,
};

/**
 * enum nvme_id_ns_attr - Specifies attributes of the namespace.
 * @NVME_NS_NSATTR_WRITE_PROTECTED: If set, then the namespace is currently
 * 				    write protected and all write access to the
 * 				    namespace shall fail.
 */
enum nvme_id_ns_attr {
	NVME_NS_NSATTR_WRITE_PROTECTED	= 1 << 0
};

/**
 * struct nvme_ns_id_desc -
 * @nidt: Namespace Identifier Type, see &enum nvme_ns_id_desc_nidt
 * @nidl: Namespace Identifier Length contains the length in bytes of the
 * 	  &struct nvme_id_ns.nid.
 * @nid:  Namespace Identifier contains a value that is globally unique and
 * 	  assigned to the namespace when the namespace is created. The length
 * 	  is defined in &struct nvme_id_ns.nidl.
 */
struct nvme_ns_id_desc {
	__u8	nidt;
	__u8	nidl;
	__le16	reserved;
	__u8	nid[];
};

/**
 * enum nvme_ns_id_desc_nidt - Known namespace identifier types
 * @NVME_NIDT_EUI64: IEEE Extended Unique Identifier, the NID field contains a
 * 		     copy of the EUI64 field in the struct nvme_id_ns.eui64.
 * @NVME_NIDT_NGUID: Namespace Globally Unique Identifier, the NID field
 * 		     contains a copy of the NGUID field in struct nvme_id_ns.nguid.
 * @NVME_NIDT_UUID:  The NID field contains a 128-bit Universally Unique
 * 		     Identifier (UUID) as specified in RFC 4122.
 */
enum nvme_ns_id_desc_nidt {
	NVME_NIDT_EUI64		= 1,
	NVME_NIDT_NGUID		= 2,
	NVME_NIDT_UUID		= 3,
};

/**
 * struct nvme_nvmset_attr - NVM Set Attributes Entry
 * @id:			    NVM Set Identifier
 * @endurance_group_id:	    Endurance Group Identifier
 * @random_4k_read_typical: Random 4 KiB Read Typical indicates the typical
 * 			    time to complete a 4 KiB random read in 100
 * 			    nanosecond units when the NVM Set is in a
 * 			    Predictable Latency Mode Deterministic Window and
 * 			    there is 1 outstanding command per NVM Set.
 * @opt_write_size:
 * @total_nvmset_cap:
 * @unalloc_nvmset_cap:
 */
struct nvme_nvmset_attr {
	__le16			id;
	__le16			endurance_group_id;
	__u8			rsvd4[4];
	__le32			random_4k_read_typical;
	__le32			opt_write_size;
	__u8			total_nvmset_cap[16];
	__u8			unalloc_nvmset_cap[16];
	__u8			rsvd48[80];
};

/**
 * struct nvme_id_nvmset_list -
 * @nid;
 * @ent:;
 */
struct nvme_id_nvmset_list {
	__u8			nid;
	__u8			rsvd1[127];
	struct nvme_nvmset_attr	ent[NVME_ID_NVMSET_LIST_MAX];
};

/**
 * struct nvme_id_ns_granularity_desc -
 * @namespace_size_granularity:
 * @namespace_capacity_granularity:
 */
struct nvme_id_ns_granularity_desc {
	__le64			namespace_size_granularity;
	__le64			namespace_capacity_granularity;
};

/**
 * struct nvme_id_ns_granularity_list -
 * @attributes:
 * @num_descriptors:
 * @entry:
 */
struct nvme_id_ns_granularity_list {
	__le32			attributes;
	__u8			num_descriptors;
	__u8			rsvd[27];
	struct nvme_id_ns_granularity_desc entry[NVME_ID_ND_DESCRIPTOR_MAX];
	__u8			rsvd288[3808];
};

/**
 * struct nvme_id_uuid_list_entry -
 * @header:
 * @uuid:
 */
struct nvme_id_uuid_list_entry {
	__u8			header;
	__u8			rsvd1[15];
	__u8			uuid[16];
};

/**
 * enum -
 * @NVME_ID_UUID_HDR_ASSOCIATION_MASK:
 * @NVME_ID_UUID_ASSOCIATION_NONE:
 * @NVME_ID_UUID_ASSOCIATION_VENDOR:
 * @NVME_ID_UUID_ASSOCIATION_SUBSYSTEM_VENDOR:
 */
enum {
	NVME_ID_UUID_HDR_ASSOCIATION_MASK		= 0x3,
	NVME_ID_UUID_ASSOCIATION_NONE			= 0,
	NVME_ID_UUID_ASSOCIATION_VENDOR			= 1,
	NVME_ID_UUID_ASSOCIATION_SUBSYSTEM_VENDOR	= 2,
};

/**
 * struct nvme_id_uuid_list -
 * @entry:
 */
struct nvme_id_uuid_list {
	__u8	rsvd0[32];
	struct nvme_id_uuid_list_entry entry[NVME_ID_UUID_LIST_MAX];
};

/**
 * struct nvme_ctrl_list -
 * @num;
 * @identifier:
 */
struct nvme_ctrl_list {
	__le16 num;
	__le16 identifier[NVME_ID_CTRL_LIST_MAX];
};

/**
 * struct nvme_ns_list -
 * @ns:
 */
struct nvme_ns_list {
	__le32 ns[NVME_ID_NS_LIST_MAX];
};

/**
 * struct nvme_primary_ctrl_cap -
 * @cntlid:
 * @portid:
 * @crt:
 * @vqfrt:
 * @vqrfa:
 * @vqrfap:
 * @vqprt:
 * @vqfrsm:
 * @vqgran:
 * @vifrt:
 * @virfa:
 * @virfap:
 * @viprt:
 * @vifrsm:
 * @vigran:
 */
struct nvme_primary_ctrl_cap {
	__le16	cntlid;
	__le16	portid;
	__u8	crt;
	__u8	rsvd5[27];
	__le32	vqfrt;
	__le32	vqrfa;
	__le16	vqrfap;
	__le16	vqprt;
	__le16	vqfrsm;
	__le16	vqgran;
	__u8	rsvd48[16];
	__le32	vifrt;
	__le32	virfa;
	__le16	virfap;
	__le16	viprt;
	__le16	vifrsm;
	__le16	vigran;
	__u8	rsvd80[4016];
};

/**
 * struct nvme_secondary_ctrl -
 * @scid:
 * @pcid:
 * @scs:
 * @vfn:
 * @nvq:
 * @nvi:
 */
struct nvme_secondary_ctrl {
	__le16 scid;
	__le16 pcid;
	__u8   scs;
	__u8   rsvd5[3];
	__le16 vfn;
	__le16 nvq;
	__le16 nvi;
	__u8   rsvd14[18];
};

/**
 * struct nvme_secondary_ctrl_list -
 * @num;
 * @sc_entry:
 */
struct nvme_secondary_ctrl_list {
	__u8   num;
	__u8   rsvd[31];
	struct nvme_secondary_ctrl sc_entry[NVME_ID_SECONDARY_CTRL_MAX];
};

/**
 * struct nvme_error_log_page -
 */
struct nvme_error_log_page {
	__le64	error_count;
	__le16	sqid;
	__le16	cmdid;
	__le16	status_field;
	__le16	parm_error_location;
	__le64	lba;
	__le32	nsid;
	__u8	vs;
	__u8	trtype;
	__u8	rsvd[2];
	__le64	cs;
	__le16	trtype_spec_info;
	__u8	rsvd2[22];
};

/**
 * enum -
 * @NVME_ERR_PEL_BYTE_MASK:
 * @NVME_ERR_PEL_BIT_MASK:
 */
enum {
	NVME_ERR_PEL_BYTE_MASK	= 0xf,
	NVME_ERR_PEL_BIT_MASK	= 0x70,
};

/**
 * struct nvme_smart_log -
 * @critical_warning:
 * @temperature:
 * @avail_spare:
 * @spare_thresh:
 * @percent_used:
 * @endu_grp_crit_warn_sumry:
 * @data_units_read:
 * @data_units_written:
 * @host_reads:
 * @host_writes:
 * @ctrl_busy_time:
 * @power_cycles:
 * @power_on_hours:
 * @unsafe_shutdowns:
 * @media_errors:
 * @num_err_log_entries:
 * @warning_temp_time:
 * @critical_comp_time:
 * @temp_sensor:
 * @thm_temp1_trans_count:
 * @thm_temp2_trans_count:
 * @thm_temp1_total_time:
 * @thm_temp2_total_time:
 */
struct nvme_smart_log {
	__u8			critical_warning;
	__u8			temperature[2];
	__u8			avail_spare;
	__u8			spare_thresh;
	__u8			percent_used;
	__u8			endu_grp_crit_warn_sumry;
	__u8			rsvd7[25];
	__u8			data_units_read[16];
	__u8			data_units_written[16];
	__u8			host_reads[16];
	__u8			host_writes[16];
	__u8			ctrl_busy_time[16];
	__u8			power_cycles[16];
	__u8			power_on_hours[16];
	__u8			unsafe_shutdowns[16];
	__u8			media_errors[16];
	__u8			num_err_log_entries[16];
	__le32			warning_temp_time;
	__le32			critical_comp_time;
	__le16			temp_sensor[8];
	__le32			thm_temp1_trans_count;
	__le32			thm_temp2_trans_count;
	__le32			thm_temp1_total_time;
	__le32			thm_temp2_total_time;
	__u8			rsvd232[280];
};

/**
 * enum -
 * @NVME_SMART_CRIT_SPARE:
 * @NVME_SMART_CRIT_TEMPERATURE:
 * @NVME_SMART_CRIT_DEGRADED:
 * @NVME_SMART_CRIT_MEDIA:
 * @NVME_SMART_CRIT_VOLATILE_MEMORY:
 * @NVME_SMART_CRIT_PMR_RO:
 */
enum {
	NVME_SMART_CRIT_SPARE		= 1 << 0,
	NVME_SMART_CRIT_TEMPERATURE	= 1 << 1,
	NVME_SMART_CRIT_DEGRADED	= 1 << 2,
	NVME_SMART_CRIT_MEDIA		= 1 << 3,
	NVME_SMART_CRIT_VOLATILE_MEMORY	= 1 << 4,
	NVME_SMART_CRIT_PMR_RO		= 1 << 5,
};

/**
 * enum -
 * @NVME_SMART_EGCW_SPARE:
 * @NVME_SMART_EGCW_DEGRADED:
 * @NVME_SMART_EGCW_RO:
 */
enum {
	NVME_SMART_EGCW_SPARE		= 1 << 0,
	NVME_SMART_EGCW_DEGRADED	= 1 << 2,
	NVME_SMART_EGCW_RO		= 1 << 3,
};

/**
 * struct nvme_firmware_slot -
 * @afi:
 * @frs:
 */
struct nvme_firmware_slot {
	__u8	afi;
	__u8	resv[7];
	char	frs[7][8];
	__u8	resv2[448];
};

/**
 * struct nvme_cmd_effects_log -
 * @acs:
 * @iocs:
 */
struct nvme_cmd_effects_log {
	__le32 acs[256];
	__le32 iocs[256];
	__u8   rsvd[2048];
};

/**
 * enum -
 * @NVME_CMD_EFFECTS_CSUPP:
 * @NVME_CMD_EFFECTS_LBCC:
 * @NVME_CMD_EFFECTS_NCC:
 * @NVME_CMD_EFFECTS_NIC:
 * @NVME_CMD_EFFECTS_CCC:
 * @NVME_CMD_EFFECTS_CSE_MASK:
 * @NVME_CMD_EFFECTS_UUID_SEL:
 */
enum {
	NVME_CMD_EFFECTS_CSUPP		= 1 << 0,
	NVME_CMD_EFFECTS_LBCC		= 1 << 1,
	NVME_CMD_EFFECTS_NCC		= 1 << 2,
	NVME_CMD_EFFECTS_NIC		= 1 << 3,
	NVME_CMD_EFFECTS_CCC		= 1 << 4,
	NVME_CMD_EFFECTS_CSE_MASK	= 3 << 16,
	NVME_CMD_EFFECTS_UUID_SEL	= 1 << 19,
};

/**
 * struct nvme_st_result -
 * @dsts:
 * @seg:
 * @vdi:
 * @poh:
 * @nsid:
 * @flba:
 * @sct:
 * @sc:
 * @vs:
 */
struct nvme_st_result {
	__u8 			dsts;
	__u8			seg;
	__u8			vdi;
	__u8			rsvd;
	__le64			poh;
	__le32			nsid;
	__le64			flba;
	__u8			sct;
	__u8			sc;
	__u8			vs[2];
} __attribute__((packed));

/**
 * enum -
 * @NVME_ST_RESULT_NO_ERR:
 * @NVME_ST_RESULT_ABORTED:
 * @NVME_ST_RESULT_CLR:
 * @NVME_ST_RESULT_NS_REMOVED:
 * @NVME_ST_RESULT_ABORTED_FORMAT:
 * @NVME_ST_RESULT_FATAL_ERR:
 * @NVME_ST_RESULT_UNKNOWN_SEG_FAIL:
 * @NVME_ST_RESULT_KNOWN_SEG_FAIL:
 * @NVME_ST_RESULT_ABORTED_UNKNOWN:
 * @NVME_ST_RESULT_ABORTED_SANITIZE:
 * @NVME_ST_RESULT_NOT_USED:
 * @NVME_ST_RESULT_MASK:
 */
enum {
	NVME_ST_RESULT_NO_ERR    	= 0x0,
	NVME_ST_RESULT_ABORTED   	= 0x1,
	NVME_ST_RESULT_CLR		= 0x2,
	NVME_ST_RESULT_NS_REMOVED	= 0x3,
	NVME_ST_RESULT_ABORTED_FORMAT	= 0x4,
	NVME_ST_RESULT_FATAL_ERR	= 0x5,
	NVME_ST_RESULT_UNKNOWN_SEG_FAIL	= 0x6,
	NVME_ST_RESULT_KNOWN_SEG_FAIL	= 0x7,
	NVME_ST_RESULT_ABORTED_UNKNOWN	= 0x8,
	NVME_ST_RESULT_ABORTED_SANITIZE	= 0x9,
	NVME_ST_RESULT_NOT_USED		= 0xf,
	NVME_ST_RESULT_MASK		= 0xf,
};

/**
 * enum -
 * @NVME_ST_CODE_NONE:
 * @NVME_ST_CODE_SHORT:
 * @NVME_ST_CODE_EXTENDED:
 * @NVME_ST_CODE_VS:
 */
enum {
	NVME_ST_CODE_SHIFT		= 4,
	NVME_ST_CODE_RESRVED		= 0x0,
	NVME_ST_CODE_SHORT		= 0x1,
	NVME_ST_CODE_EXTENDED		= 0x2,
	NVME_ST_CODE_VS			= 0xe,
};

/**
 * enum -
 * @NVME_ST_VALID_DIAG_INFO_NSID:
 * @NVME_ST_VALID_DIAG_INFO_FLBA:
 * @NVME_ST_VALID_DIAG_INFO_SCT:
 * @NVME_ST_VALID_DIAG_INFO_SC:
 */
enum {
	NVME_ST_VALID_DIAG_INFO_NSID		= 1 << 0,
	NVME_ST_VALID_DIAG_INFO_FLBA		= 1 << 1,
	NVME_ST_VALID_DIAG_INFO_SCT		= 1 << 2,
	NVME_ST_VALID_DIAG_INFO_SC		= 1 << 3,
};


/**
 * struct nvme_self_test_log -
 * @current_operation:
 * @completion:
 * @result:
 */
struct nvme_self_test_log {
	__u8			current_operation;
	__u8			completion;
	__u8			rsvd[2];
	struct nvme_st_result	result[NVME_LOG_ST_MAX_RESULTS];
} __attribute__((packed));

/**
 * struct nvme_telemetry_log - Retrieve internal data specific to the
 * 			       manufacturer.
 * @lpi:       Log Identifier, either #NVME_LOG_LID_TELEMETRY_HOST or
 * 	       #NVME_LOG_LID_TELEMETRY_CTRL
 * @ieee:      IEEE OUI Identifier is the Organization Unique Identifier (OUI)
 * 	       for the controller vendor that is able to interpret the data.
 * @dalb1:     Telemetry Controller-Initiated Data Area 1 Last Block is
 * 	       the value of the last block in this area.
 * @dalb3:     Telemetry Controller-Initiated Data Area 1 Last Block is
 * 	       the value of the last block in this area.
 * @dalb3:     Telemetry Controller-Initiated Data Area 1 Last Block is
 * 	       the value of the last block in this area.
 * @ctrlavail: Telemetry Controller-Initiated Data Available, if cleared,
 * 	       then the controller telemetry log does not contain saved
 * 	       internal controller state. If this field is set to 1h, the
 * 	       controller log contains saved internal controller state. If
 * 	       this field is set to 1h, the data will be latched until the
 * 	       host releases it by reading the log with RAE cleared.
 * @ctrldgn:   Telemetry Controller-Initiated Data Generation Number is
 * 	       a value that is incremented each time the controller initiates a
 * 	       capture of its internal controller state in the controller .
 * @rsnident:  Reason Identifieris a vendor specific identifier that describes
 * 	       the operating conditions of the controller at the time of
 * 	       capture.
 * @data_area: Telemetry data blocks, vendor specific information data.
 *
 * This log consists of a header describing the log and zero or more Telemetry
 * Data Blocks. All Telemetry Data Blocks are %NVME_LOG_TELEM_BLOCK_SIZE, 512
 * bytes, in size. This log captures the controller’s internal state.
 */
struct nvme_telemetry_log {
	__u8	lpi;
	__u8	rsvd1[4];
	__u8	ieee[3];
	__le16	dalb1;
	__le16	dalb2;
	__le16	dalb3;
	__u8	rsvd14[368];
	__u8	ctrlavail;
	__u8	ctrldgn;
	__u8	rsnident[128];
	__u8	data_area[];
};

/**
 * struct nvme_endurance_group_log -
 * @critical_warning:
 * @avl_spare:
 * @avl_spare_threshold:
 * @percent_used:
 * @endurance_estimate:
 * @data_units_read:
 * @data_units_written:
 * @media_units_written:
 * @host_read_cmds:
 * @host_write_cmds:
 * @media_data_integrity_err:
 * @num_err_info_log_entries:
 */
struct nvme_endurance_group_log {
	__u8	critical_warning;
	__u8	rsvd1[2];
	__u8	avl_spare;
	__u8	avl_spare_threshold;
	__u8	percent_used;
	__u8	rsvd6[26];
	__u8	endurance_estimate[16];
	__u8	data_units_read[16];
	__u8	data_units_written[16];
	__u8	media_units_written[16];
	__u8	host_read_cmds[16];
	__u8	host_write_cmds[16];
	__u8	media_data_integrity_err[16];
	__u8	num_err_info_log_entries[16];
	__u8	rsvd160[352];
};

/**
 * enum -
 * @NVME_EG_CRITICAL_WARNING_SPARE:
 * @NVME_EG_CRITICAL_WARNING_DEGRADED:
 * @NVME_EG_CRITICAL_WARNING_READ_ONLY:
 */
enum nvme_eg_critical_warning_flags {
	NVME_EG_CRITICAL_WARNING_SPARE		= 1 << 0,
	NVME_EG_CRITICAL_WARNING_DEGRADED	= 1 << 2,
	NVME_EG_CRITICAL_WARNING_READ_ONLY	= 1 << 3,
};

/**
 * struct nvme_aggregate_endurance_group_event -
 * @num_entries:
 * @entries:
 */
struct nvme_aggregate_endurance_group_event {
	__le64	num_entries;
	__le16	entries[];
};

/**
 * struct nvme_nvmset_predictable_lat_log -
 * @status:
 * @event_type:
 * @dtwin_rt:
 * @dtwin_wt:
 * @dtwin_tmax:
 * @dtwin_tmin_hi:
 * @dtwin_tmin_lo:
 * @dtwin_re:
 * @dtwin_we:
 * @dtwin_te:
 */
struct nvme_nvmset_predictable_lat_log {
	__u8	status;
	__u8	rsvd1;
	__le16	event_type;
	__u8	rsvd4[28];
	__le64	dtwin_rt;
	__le64	dtwin_wt;
	__le64	dtwin_tmax;
	__le64	dtwin_tmin_hi;
	__le64	dtwin_tmin_lo;
	__u8	rsvd72[56];
	__le64	dtwin_re;
	__le64	dtwin_we;
	__le64	dtwin_te;
	__u8	rsvd152[360];
};

/**
 * enum -
 * @NVME_NVMSET_PL_STATUS_DISABLED:
 * @NVME_NVMSET_PL_STATUS_DTWIN:
 * @NVME_NVMSET_PL_STATUS_NDWIN:
 */
enum {
	NVME_NVMSET_PL_STATUS_DISABLED	= 0,
	NVME_NVMSET_PL_STATUS_DTWIN	= 1,
	NVME_NVMSET_PL_STATUS_NDWIN	= 2,
};

/**
 * enum -
 * @NVME_NVMSET_PL_EVENT_DTWIN_READ_WARN:
 * @NVME_NVMSET_PL_EVENT_DTWIN_WRITE_WARN:
 * @NVME_NVMSET_PL_EVENT_DTWIN_TIME_WARN:
 * @NVME_NVMSET_PL_EVENT_DTWIN_EXCEEDED:
 * @NVME_NVMSET_PL_EVENT_DTWIN_EXCURSION:
 */
enum {
	NVME_NVMSET_PL_EVENT_DTWIN_READ_WARN	= 1 << 0,
	NVME_NVMSET_PL_EVENT_DTWIN_WRITE_WARN	= 1 << 1,
	NVME_NVMSET_PL_EVENT_DTWIN_TIME_WARN	= 1 << 2,
	NVME_NVMSET_PL_EVENT_DTWIN_EXCEEDED	= 1 << 14,
	NVME_NVMSET_PL_EVENT_DTWIN_EXCURSION	= 1 << 15,
};

/**
 * struct nvme_aggregate_predictable_lat_event -
 * @num_entries:
 * @entries:
 */
struct nvme_aggregate_predictable_lat_event {
	__le64	num_entries;
	__le16	entries[];
};

/**
 * struct nvme_ana_group_desc -
 * @grpid:
 * @nnsids:
 * @chgcnt:
 * @state:
 * @nsids:
 */
struct nvme_ana_group_desc {
	__le32  grpid;
	__le32  nnsids;
	__le64  chgcnt;
	__u8    state;
	__u8    rsvd17[15];
	__le32  nsids[];
};

/**
 * enum nvme_ana_state -
 * @NVME_ANA_STATE_OPTIMIZED:
 * @NVME_ANA_STATE_NONOPTIMIZED:
 * @NVME_ANA_STATE_INACCESSIBLE:
 * @NVME_ANA_STATE_PERSISTENT_LOSS:
 * @NVME_ANA_STATE_CHANGE:
 */
enum nvme_ana_state {
	NVME_ANA_STATE_OPTIMIZED	= 0x1,
	NVME_ANA_STATE_NONOPTIMIZED	= 0x2,
	NVME_ANA_STATE_INACCESSIBLE	= 0x3,
	NVME_ANA_STATE_PERSISTENT_LOSS	= 0x4,
	NVME_ANA_STATE_CHANGE		= 0xf,
};

/**
 * struct nvme_ana_log -
 * @chgcnt:
 * @ngrps:
 * @descs:
 */
struct nvme_ana_log {
	__le64	chgcnt;
	__le16	ngrps;
	__u8	rsvd10[6];
	struct nvme_ana_group_desc descs[];
};

/**
 * struct nvme_persistent_event_log -
 * @lid:
 * @ttl:
 * @rv:
 * @lht:
 * @ts:
 * @poh:
 * @pcc:
 * @vid:
 * @ssvid:
 * @sn:
 * @mn:
 * @subnqn:
 * @seb:
 */
struct nvme_persistent_event_log {
	__u8	lid;
	__u8	rsvd1[3];
	__le32	ttl;
	__u8	rv;
	__u8	rsvd17;
	__le16	lht;
	__le64	ts;
	__u8	poh[16];
	__le64	pcc;
	__le16	vid;
	__le16	ssvid;
	char	sn[20];
	char	mn[40];
	char	subnqn[NVME_NQN_LENGTH];
	__u8	rsvd372;
	__u8	seb[32];
};

/**
 * struct nvme_lba_rd -
 * @rslba:
 * @rnlb:
 */
struct nvme_lba_rd {
	__le64	rslba;
	__le32	rnlb;
	__u8	rsvd12[4];
};

/**
 * struct nvme_lbas_ns_element -
 * @neid:
 * @nrld:
 * @ratype:
 * @lba_rd:
 */
struct nvme_lbas_ns_element {
	__le32	neid;
	__le32	nrld;
	__u8	ratype;
	__u8	rsvd8[7];
	struct	nvme_lba_rd lba_rd[];
};

/**
 * enum nvme_lba_status_atype -
 * @NVME_LBA_STATUS_ATYPE_SCAN_UNTRACKED:
 * @NVME_LBA_STATUS_ATYPE_SCAN_TRACKED:
 */
enum nvme_lba_status_atype {
	NVME_LBA_STATUS_ATYPE_SCAN_UNTRACKED			= 0x10,
	NVME_LBA_STATUS_ATYPE_SCAN_TRACKED			= 0x11,
};

/**
 * struct nvme_lba_status_log -
 * @lslplen:
 * @nlslne:
 * @estulb:
 * @lsgc:
 * @elements:
 */
struct nvme_lba_status_log {
	__le32	lslplen;
	__le32	nlslne;
	__le32	estulb;
	__u8	rsvd12[2];
	__le16	lsgc;
	struct nvme_lbas_ns_element elements[];
};

/**
 * struct nvme_eg_event_aggregate_log -
 * @nr_entries:
 * @egids:
 */
struct nvme_eg_event_aggregate_log {
	__le64	nr_entries;
	__le16	egids[];
};

/**
 * struct nvme_resv_notification_log -
 * @lpc:
 * @rnlpt: See &enum nvme_resv_notify_rnlpt.
 * @nalp:
 * @nsid:
 */
struct nvme_resv_notification_log {
	__le64	lpc;
	__u8	rnlpt;
	__u8	nalp;
	__u8	rsvd9[2];
	__le32	nsid;
	__u8	rsvd16[48];
};

/**
 * enum nvme_resv_notify_rnlpt -
 * @NVME_RESV_NOTIFY_RNLPT_EMPTY:
 * @NVME_RESV_NOTIFY_RNLPT_REGISTRATION_PREEMPTED:
 * @NVME_RESV_NOTIFY_RNLPT_RESERVATION_RELEASED:
 * @NVME_RESV_NOTIFY_RNLPT_RESERVATION_PREEMPTED:
 */
enum nvme_resv_notify_rnlpt {
	NVME_RESV_NOTIFY_RNLPT_EMPTY			= 0,
	NVME_RESV_NOTIFY_RNLPT_REGISTRATION_PREEMPTED	= 1,
	NVME_RESV_NOTIFY_RNLPT_RESERVATION_RELEASED	= 2,
	NVME_RESV_NOTIFY_RNLPT_RESERVATION_PREEMPTED	= 3,
};

/**
 * struct nvme_sanitize_log_page -
 * @sprog:
 * @sstat:
 * @scdw10:
 * @eto:
 * @etbe:
 * @etce:
 * @etond:
 * @etbend:
 * @etcend:
 */
struct nvme_sanitize_log_page {
	__le16	sprog;
	__le16	sstat;
	__le32	scdw10;
	__le32	eto;
	__le32	etbe;
	__le32	etce;
	__le32	etond;
	__le32	etbend;
	__le32	etcend;
	__u8	rsvd32[480];
};

/**
 * enum nvme_sanitize_sstat -
 * @NVME_SANITIZE_SSTAT_STATUS_MASK:
 * @NVME_SANITIZE_SSTAT_STATUS_NEVER_SANITIZED:
 * @NVME_SANITIZE_SSTAT_STATUS_COMPLETE_SUCCESS:
 * @NVME_SANITIZE_SSTAT_STATUS_IN_PROGESS:
 * @NVME_SANITIZE_SSTAT_STATUS_COMPLETED_FAILED:
 * @NVME_SANITIZE_SSTAT_STATUS_ND_COMPLETE_SUCCESS:
 */
enum nvme_sanitize_sstat {
	NVME_SANITIZE_SSTAT_STATUS_MASK			= 0x7,
	NVME_SANITIZE_SSTAT_STATUS_NEVER_SANITIZED	= 0,
	NVME_SANITIZE_SSTAT_STATUS_COMPLETE_SUCCESS	= 1,
	NVME_SANITIZE_SSTAT_STATUS_IN_PROGESS		= 2,
	NVME_SANITIZE_SSTAT_STATUS_COMPLETED_FAILED	= 3,
	NVME_SANITIZE_SSTAT_STATUS_ND_COMPLETE_SUCCESS	= 4,
	NVME_SANITIZE_SSTAT_COMPLETED_PASSES_MASK	= 0xf8,
	NVME_SANITIZE_SSTAT_COMPLETED_PASSES_SHIFT	= 3,
	NVME_SANITIZE_SSTAT_GLOBAL_DATA_ERASED		= 1 << 8,
};

/**
 * struct nvme_lba_status_desc -
 * @dslba:
 * @nlb:
 * @status:
 */
struct nvme_lba_status_desc {
	__le64	dslba;
	__le32	nlb;
	__u8	rsvd12;
	__u8	status;
	__u8	rsvd14[2];
};

/**
 * struct nvme_lba_status -
 * @nlsd:
 * @cmpc:
 * @descs:
 */
struct nvme_lba_status {
	__le32	nlsd;
	__u8	cmpc;
	__u8	rsvd5[3];
	struct nvme_lba_status_desc descs[];
};

/**
 * struct nvme_feat_auto_pst -
 * @apst_entry: See &enum nvme_apst_entry
 */
struct nvme_feat_auto_pst {
	__le64	apst_entry[32];
};

/**
 * enum nvme_apst_entry -
 */
enum nvme_apst_entry {
	NVME_APST_ENTRY_ITPS_MASK = 0xf8,
	NVME_APST_ENTRY_ITPS_SHIFT = 3,
	NVME_APST_ENTRY_ITPT_MASK = 0xffffff00,
	NVME_APST_ENTRY_ITPT_SHIFT = 8,
};

/**
 * struct nvme_timestamp -
 * timestamp:
 * @attr:
 */
struct nvme_timestamp {
	__u8 timestamp[6];
	__u8 attr;
	__u8 rsvd;
};

/**
 * struct nvme_lba_range_type_entry -
 * @type:
 * @attributes:
 * @slba:
 * @nlb:
 * @guid:
 */
struct nvme_lba_range_type_entry {
	__u8	type;
	__u8	attributes;
	__u8	rsvd2[14];
	__u64	slba;
	__u64	nlb;
	__u8	guid[16];
	__u8	rsvd48[16];
};

/**
 * enum -
 * @NVME_LBART_TYPE_GP:
 * @NVME_LBART_TYPE_FS:
 * @NVME_LBART_TYPE_RAID:
 * @NVME_LBART_TYPE_CACHE:
 * @NVME_LBART_TYPE_SWAP:
 * @NVME_LBART_ATTRIB_TEMP:
 * @NVME_LBART_ATTRIB_HIDE:
 */
enum {
	NVME_LBART_TYPE_GP	= 0,
	NVME_LBART_TYPE_FS	= 1,
	NVME_LBART_TYPE_RAID	= 2,
	NVME_LBART_TYPE_CACHE	= 3,
	NVME_LBART_TYPE_SWAP	= 4,
	NVME_LBART_ATTRIB_TEMP	= 1 << 0,
	NVME_LBART_ATTRIB_HIDE	= 1 << 1,
};

/**
 * struct nvme_lba_range_type -
 * @entry:
 */
struct nvme_lba_range_type {
	struct nvme_lba_range_type_entry entry[NVME_FEAT_LBA_RANGE_MAX];
};

/**
 * struct nvme_plm_config -
 * @ee;
 * @dtwinrt;
 * @dtwinwt;
 * @dtwintt;
 */
struct nvme_plm_config {
	__le16	ee;
	__u8	rsvd2[30];
	__le64	dtwinrt;
	__le64	dtwinwt;
	__le64	dtwintt;
	__u8	rsvd56[456];
};

/**
 * struct nvme_feat_host_behavior -
 * @acre:
 */
struct nvme_feat_host_behavior {
	__u8 acre;
	__u8 rsvd1[511];
};

/**
 * enum -
 * @NVME_ENABLE_ACRE:
 */
enum {
	NVME_ENABLE_ACRE        = 1 << 0,
};

/**
 * struct nvme_dsm_range -
 * @cattr:
 * @nlb:
 * @slba:
 */
struct nvme_dsm_range {
	__le32	cattr;
	__le32	nlb;
	__le64	slba;
};

/**
 * struct nvme_registered_ctrl -
 * @cntlid:
 * @rcsts:
 * @hostid:
 * @rkey:
 */
struct nvme_registered_ctrl {
	__le16	cntlid;
	__u8	rcsts;
	__u8	rsvd3[5];
	__le64	hostid;
	__le64	rkey;
};

/**
 * struct nvme_registered_ctrl_ext -
 * @cntlid:
 * @rcsts:
 * @rkey:
 * @hostid:
 */
struct nvme_registered_ctrl_ext {
	__le16	cntlid;
	__u8	rcsts;
	__u8	rsvd3[5];
	__le64	rkey;
	__u8	hostid[16];
	__u8	rsvd32[32];
};

/**
 * struct nvme_reservation_status -{
 * @gen:
 * @rtype:
 * @regctl:
 * @ptpls:
 * @regctl_eds:
 * @regctl_ds:
 */
struct nvme_reservation_status {
	__le32	gen;
	__u8	rtype;
	__u8	regctl[2];
	__u8	rsvd7[2];
	__u8	ptpls;
	__u8	rsvd10[14];
	union {
		struct {
			__u8	rsvd24[40];
			struct nvme_registered_ctrl_ext regctl_eds[0];
		};
		struct nvme_registered_ctrl regctl_ds[0];
	};
};

/**
 * struct nvme_streams_directive_params -
 */
struct nvme_streams_directive_params {
	__le16	msl;
	__le16	nssa;
	__le16	nsso;
	__u8	nssc;
	__u8	rsvd[9];
	__le32	sws;
	__le16	sgs;
	__le16	nsa;
	__le16	nso;
	__u8	rsvd2[6];
};

/**
 * struct nvme_streams_directive_status -
 */
struct nvme_streams_directive_status {
	__le16	osc;
	__le16	sid[];
};

/**
 * struct nvme_id_directives -
 */
struct nvme_id_directives {
	__u8	supported[32];
	__u8	enabled[32];
	__u8	rsvd64[4032];
};

/**
 * enum -
 */
enum {
	NVME_ID_DIR_ID_BIT	= 0,
	NVME_ID_DIR_SD_BIT	= 1,
};

/**
 * struct nvme_host_mem_buf_desc -
 */
struct nvme_host_mem_buf_desc {
	__le64			addr;
	__le32			size;
	__u32			rsvd;
};

/**
 * enum nvme_ae_type -
 * @NVME_AER_ERROR:
 * @NVME_AER_SMART:
 * @NVME_AER_NOTICE:
 * @NVME_AER_CSS:
 * @NVME_AER_VS:
 */
enum nvme_ae_type {
        NVME_AER_ERROR				= 0,
        NVME_AER_SMART				= 1,
        NVME_AER_NOTICE				= 2,
        NVME_AER_CSS				= 6,
        NVME_AER_VS				= 7,
};
/**
 * enum nvme_ae_info_error -
 * @NVME_AER_ERROR_INVALID_DB_REG:
 * @NVME_AER_ERROR_INVALID_DB_VAL:
 * @NVME_AER_ERROR_DIAG_FAILURE:
 * @NVME_AER_ERROR_PERSISTENT_INTERNAL_ERROR:
 * @NVME_AER_ERROR_TRANSIENT_INTERNAL_ERROR:
 * @NVME_AER_ERROR_FW_IMAGE_LOAD_ERROR:
 */
enum nvme_ae_info_error {
	NVME_AER_ERROR_INVALID_DB_REG			= 0x00,
	NVME_AER_ERROR_INVALID_DB_VAL			= 0x01,
	NVME_AER_ERROR_DIAG_FAILURE			= 0x02,
	NVME_AER_ERROR_PERSISTENT_INTERNAL_ERROR	= 0x03,
	NVME_AER_ERROR_TRANSIENT_INTERNAL_ERROR		= 0x04,
	NVME_AER_ERROR_FW_IMAGE_LOAD_ERROR		= 0x05,
};

/**
 * enum nvme_ae_info_smart -
 * @NVME_AER_SMART_SUBSYSTEM_RELIABILITY:
 * @NVME_AER_SMART_TEMPERATURE_THRESHOLD:
 * @NVME_AER_SMART_SPARE_THRESHOLD:
 */
enum nvme_ae_info_smart {
	NVME_AER_SMART_SUBSYSTEM_RELIABILITY		= 0x00,
	NVME_AER_SMART_TEMPERATURE_THRESHOLD		= 0x01,
	NVME_AER_SMART_SPARE_THRESHOLD			= 0x02,
};

/**
 * enum nvme_ae_info_css_nvm -
 * @NVME_AER_CSS_NVM_RESERVATION:
 * @NVME_AER_CSS_NVM_SANITIZE_COMPLETED:
 * @NVME_AER_CSS_NVM_UNEXPECTED_SANITIZE_DEALLOC:
 */
enum nvme_ae_info_css_nvm {
	NVME_AER_CSS_NVM_RESERVATION			= 0x00,
	NVME_AER_CSS_NVM_SANITIZE_COMPLETED		= 0x01,
	NVME_AER_CSS_NVM_UNEXPECTED_SANITIZE_DEALLOC	= 0x02,
};

/**
 * enum nvme_ae_info_notice -
 * @NVME_AER_NOTICE_NS_CHANGED:
 * @NVME_AER_NOTICE_FW_ACT_STARTING:
 * @NVME_AER_NOTICE_TELEMETRY:
 * @NVME_AER_NOTICE_ANA:
 * @NVME_AER_NOTICE_PL_EVENT:
 * @NVME_AER_NOTICE_LBA_STATUS_ALERT:
 * @NVME_AER_NOTICE_EG_EVENT:
 * @NVME_AER_NOTICE_DISC_CHANGED:
 */
enum nvme_ae_info_notice {
        NVME_AER_NOTICE_NS_CHANGED			= 0x00,
        NVME_AER_NOTICE_FW_ACT_STARTING			= 0x01,
        NVME_AER_NOTICE_TELEMETRY			= 0x02,
        NVME_AER_NOTICE_ANA				= 0x03,
        NVME_AER_NOTICE_PL_EVENT			= 0x04,
        NVME_AER_NOTICE_LBA_STATUS_ALERT		= 0x05,
        NVME_AER_NOTICE_EG_EVENT			= 0x06,
        NVME_AER_NOTICE_DISC_CHANGED			= 0xf0,
};

/**
 * enum nvme_subsys_type -
 * @NVME_NQN_DISC:		Discovery type target subsystem
 * @NVME_NQN_NVME:		NVME type target subsystem
 */
enum nvme_subsys_type {
	NVME_NQN_DISC	= 1,
	NVME_NQN_NVME	= 2,
};

#define NVME_DISC_SUBSYS_NAME	"nqn.2014-08.org.nvmexpress.discovery"
#define NVME_RDMA_IP_PORT	4420

/* However the max length of a qualified name is another size */
#define NVMF_NQN_SIZE		223
#define NVMF_TRSVCID_SIZE	32

/**
 * struct nvmf_disc_log_entry - Discovery log page entry
 * @trtype:
 * @adrfam:
 * @subtype:
 * @treq:
 * @portid:
 * @cntlid:
 * @asqsz:
 * @trsvcid:
 * @subnqn:
 * @traddr:
 * @common:
 * @qptype:
 * @prtype:
 * @cms:
 * @pkey:
 * @sectype:
 */
struct nvmf_disc_log_entry {
	__u8		trtype;
	__u8		adrfam;
	__u8		subtype;
	__u8		treq;
	__le16		portid;
	__le16		cntlid;
	__le16		asqsz;
	__u8		rsvd10[22];
	char		trsvcid[NVMF_TRSVCID_SIZE];
	__u8		rsvd64[192];
	char		subnqn[NVME_NQN_LENGTH];
	char		traddr[NVMF_TRADDR_SIZE];
	union tsas {
		char		common[NVMF_TSAS_SIZE];
		struct rdma {
			__u8	qptype;
			__u8	prtype;
			__u8	cms;
			__u8	rsvd3[5];
			__u16	pkey;
			__u8	rsvd10[246];
		} rdma;
		struct tcp {
			__u8	sectype;
		} tcp;
	} tsas;
};

/**
 * enum - Transport Type codes for Discovery Log Page entry TRTYPE field
 * @NVMF_TRTYPE_UNSPECIFIED:	Not indicated
 * @NVMF_TRTYPE_RDMA:		RDMA
 * @NVMF_TRTYPE_FC:		Fibre Channel
 * @NVMF_TRTYPE_TCP:		TCP
 * @NVMF_TRTYPE_LOOP:		Reserved for host usage
 */
enum {
	NVMF_TRTYPE_UNSPECIFIED	= 0,
	NVMF_TRTYPE_RDMA	= 1,
	NVMF_TRTYPE_FC		= 2,
	NVMF_TRTYPE_TCP		= 3,
	NVMF_TRTYPE_LOOP	= 254,
	NVMF_TRTYPE_MAX,
};

/**
 * enum - Address Family codes for Discovery Log Page entry ADRFAM field
 * @NVMF_ADDR_FAMILY_PCI:	PCIe
 * @NVMF_ADDR_FAMILY_IP4:	IPv4
 * @NVMF_ADDR_FAMILY_IP6:	IPv6
 * @NVMF_ADDR_FAMILY_IB:	InfiniBand
 * @NVMF_ADDR_FAMILY_FC:	Fibre Channel
 */
enum {
	NVMF_ADDR_FAMILY_PCI	= 0,
	NVMF_ADDR_FAMILY_IP4	= 1,
	NVMF_ADDR_FAMILY_IP6	= 2,
	NVMF_ADDR_FAMILY_IB	= 3,
	NVMF_ADDR_FAMILY_FC	= 4,
};

/**
 * enum - Transport Requirements codes for Discovery Log Page entry TREQ field
 * @NVMF_TREQ_NOT_SPECIFIED:	Not specified
 * @NVMF_TREQ_REQUIRED:		Required
 * @NVMF_TREQ_NOT_REQUIRED:	Not Required
 * @NVMF_TREQ_DISABLE_SQFLOW:	SQ flow control disable supported
 */
enum {
	NVMF_TREQ_NOT_SPECIFIED		= 0,
	NVMF_TREQ_REQUIRED		= 1,
	NVMF_TREQ_NOT_REQUIRED		= 2,
	NVMF_TREQ_DISABLE_SQFLOW	= 4,
};

/**
 * enum - RDMA QP Service Type codes for Discovery Log Page entry TSAS
 *	  RDMA_QPTYPE field
 * @NVMF_RDMA_QPTYPE_CONNECTED:	Reliable Connected
 * @NVMF_RDMA_QPTYPE_DATAGRAM:	Reliable Datagram
 */
enum {
	NVMF_RDMA_QPTYPE_CONNECTED	= 1,
	NVMF_RDMA_QPTYPE_DATAGRAM	= 2,
};

/**
 * enum - RDMA Provider Type codes for Discovery Log Page entry TSAS
 * 	  RDMA_PRTYPE field
 * @NVMF_RDMA_PRTYPE_NOT_SPECIFIED: No Provider Specified
 * @NVMF_RDMA_PRTYPE_IB:	    InfiniBand
 * @NVMF_RDMA_PRTYPE_ROCE:	    InfiniBand RoCE
 * @NVMF_RDMA_PRTYPE_ROCEV2:	    InfiniBand RoCEV2
 * @NVMF_RDMA_PRTYPE_IWARP:	    iWARP
 */
enum {
	NVMF_RDMA_PRTYPE_NOT_SPECIFIED	= 1,
	NVMF_RDMA_PRTYPE_IB		= 2,
	NVMF_RDMA_PRTYPE_ROCE		= 3,
	NVMF_RDMA_PRTYPE_ROCEV2		= 4,
	NVMF_RDMA_PRTYPE_IWARP		= 5,
};

/**
 * enum - RDMA Connection Management Service Type codes for Discovery Log Page
 * 	  entry TSAS RDMA_CMS field
 * @NVMF_RDMA_CMS_RDMA_CM: Sockets based endpoint addressing
 *
 */
enum {
	NVMF_RDMA_CMS_RDMA_CM	= 1,
};

/**
 * enum -
 * @NVMF_TCP_SECTYPE_NONE: No Security
 * @NVMF_TCP_SECTYPE_TLS:  Transport Layer Security
 */
enum {
	NVMF_TCP_SECTYPE_NONE	= 0,
	NVMF_TCP_SECTYPE_TLS	= 1,
};

/**
 * struct nvmf_discovery_log -
 * @genctr:
 * @numrec:
 * @recfmt:
 * @entries:
 */
struct nvmf_discovery_log {
	__le64		genctr;
	__le64		numrec;
	__le16		recfmt;
	__u8		rsvd14[1006];
	struct nvmf_disc_log_entry entries[];
};

/**
 * struct nvmf_connect_data -
 * @hostid:
 * @cntlid:
 * @subsysnqn
 * @hostnqn
 */
struct nvmf_connect_data {
	__u8		hostid[16];
	__le16		cntlid;
	char		rsvd4[238];
	char		subsysnqn[NVME_NQN_LENGTH];
	char		hostnqn[NVME_NQN_LENGTH];
	char		rsvd5[256];
};

/**
 * struct nvme_mi_read_nvm_ss_info -
 * @nump:
 * @mjr:
 * @mnr:
 */
struct nvme_mi_read_nvm_ss_info {
	__u8	nump;
	__u8	mjr;
	__u8	mnr;
	__u8	rsvd3[29];
};

/**
 * struct nvme_mi_port_pcie -
 * @mps:
 * @sls:
 * @cls:
 * @mlw:
 * @nlw:
 * @pn:
 */
struct nvme_mi_port_pcie {
	__u8	mps;
	__u8	sls;
	__u8	cls;
	__u8	mlw;
	__u8	nlw;
	__u8	pn;
	__u8	rsvd14[18];
};

/**
 * struct nvme_mi_port_smb -
 * @vpd_addr:
 * @mvpd_freq:
 * @mme_addr:
 * @mme_freq:
 * @nvmebm:
 */
struct nvme_mi_port_smb {
	__u8	vpd_addr;
	__u8	mvpd_freq;
	__u8	mme_addr;
	__u8	mme_freq;
	__u8	nvmebm;
	__u8	rsvd13[19];
};

/**
 * struct nvme_mi_read_port_info -
 * @portt:
 * @mmctptus;
 * @meb:
 * @pcie:
 * @smb:
 */
struct nvme_mi_read_port_info {
	__u8	portt;
	__u8	rsvd1;
	__le16	mmctptus;
	__le32	meb;
	union {
		struct nvme_mi_port_pcie pcie;
		struct nvme_mi_port_smb smb;
	};
};

/**
 * struct nvme_mi_read_ctrl_info -
 * @portid;
 * @prii;
 * @pri;
 * @vid;
 * @did;
 * @ssvid;
 * @ssid;
 */
struct nvme_mi_read_ctrl_info {
	__u8	portid;
	__u8	rsvd1[4];
	__u8	prii;
	__le16	pri;
	__le16	vid;
	__le16	did;
	__le16	ssvid;
	__le16	ssid;
	__u8	rsvd16[16];
};

/**
 * struct nvme_mi_osc -
 * @type;
 * @opc;
 */
struct nvme_mi_osc {
	__u8	type;
	__u8	opc;
};

/**
 * struct nvme_mi_read_sc_list -
 * @numcmd:
 * @cmds:
 */
struct nvme_mi_read_sc_list {
	__le16	numcmd;
	struct nvme_mi_osc cmds[];
};

/**
 * struct nvme_mi_nvm_ss_health_status -
 * @nss:
 * @sw:
 * @ctemp:
 * @pdlu:
 * @ccs:
 */
struct nvme_mi_nvm_ss_health_status {
	__u8	nss;
	__u8	sw;
	__u8	ctemp;
	__u8	pdlu;
	__le16	ccs;
	__u8	rsvd8[2];
};

/**
 * enum  -
 * @NVME_MI_CCS_RDY:
 * @NVME_MI_CSS_CFS:
 * @NVME_MI_CSS_SHST:
 * @NVME_MI_CSS_NSSRO:
 * @NVME_MI_CSS_CECO:
 * @NVME_MI_CSS_NAC:
 * @NVME_MI_CSS_FA:
 * @NVME_MI_CSS_CSTS:
 * @NVME_MI_CSS_CTEMP:
 * @NVME_MI_CSS_PDLU:
 * @NVME_MI_CSS_SPARE:
 * @NVME_MI_CSS_CCWARN:
 */
enum {
	NVME_MI_CCS_RDY		= 1 << 0,
	NVME_MI_CSS_CFS		= 1 << 1,
	NVME_MI_CSS_SHST	= 1 << 2,
	NVME_MI_CSS_NSSRO	= 1 << 4,
	NVME_MI_CSS_CECO	= 1 << 5,
	NVME_MI_CSS_NAC		= 1 << 6,
	NVME_MI_CSS_FA		= 1 << 7,
	NVME_MI_CSS_CSTS	= 1 << 8,
	NVME_MI_CSS_CTEMP	= 1 << 9,
	NVME_MI_CSS_PDLU	= 1 << 10,
	NVME_MI_CSS_SPARE	= 1 << 11,
	NVME_MI_CSS_CCWARN	= 1 << 12,
};

/**
 * struct nvme_mi_ctrl_heal_status -
 * @ctlid:
 * @csts:
 * @ctemp:
 * @pdlu:
 * @spare:
 * @cwarn:
 */
struct nvme_mi_ctrl_heal_status {
	__le16	ctlid;
	__le16	csts;
	__le16	ctemp;
	__u8	pdlu;
	__u8	spare;
	__u8	cwarn;
	__u8	rsvd9[7];
};

/**
 * enum -
 * @NVME_MI_CSTS_RDY:
 * @NVME_MI_CSTS_CFS:
 * @NVME_MI_CSTS_SHST:
 * @NVME_MI_CSTS_NSSRO:
 * @NVME_MI_CSTS_CECO:
 * @NVME_MI_CSTS_NAC:
 * @NVME_MI_CSTS_FA:
 * @NVME_MI_CWARN_ST:
 * @NVME_MI_CWARN_TAUT:
 * @NVME_MI_CWARN_RD:
 * @NVME_MI_CWARN_RO:
 * @NVME_MI_CWARN_VMBF:
 */
enum {
	NVME_MI_CSTS_RDY	= 1 << 0,
	NVME_MI_CSTS_CFS	= 1 << 1,
	NVME_MI_CSTS_SHST	= 1 << 2,
	NVME_MI_CSTS_NSSRO	= 1 << 4,
	NVME_MI_CSTS_CECO	= 1 << 5,
	NVME_MI_CSTS_NAC	= 1 << 6,
	NVME_MI_CSTS_FA		= 1 << 7,
	NVME_MI_CWARN_ST	= 1 << 0,
	NVME_MI_CWARN_TAUT	= 1 << 1,
	NVME_MI_CWARN_RD	= 1 << 2,
	NVME_MI_CWARN_RO	= 1 << 3,
	NVME_MI_CWARN_VMBF	= 1 << 4,
};

/**
 * struct nvme_mi_vpd_mra -
 * @nmravn;
 * @ff;
 * @i18vpwr;
 * @m18vpwr;
 * @i33vpwr;
 * @m33vpwr;
 * @m33vapsr;
 * @i5vapsr;
 * @m5vapsr;
 * @i12vapsr;
 * @m12vapsr;
 * @mtl;
 * @tnvmcap[16];
 */
struct nvme_mi_vpd_mra {
	__u8	nmravn;
	__u8	ff;
	__u8	rsvd7[6];
	__u8	i18vpwr;
	__u8	m18vpwr;
	__u8	i33vpwr;
	__u8	m33vpwr;
	__u8	rsvd17;
	__u8	m33vapsr;
	__u8	i5vapsr;
	__u8	m5vapsr;
	__u8	i12vapsr;
	__u8	m12vapsr;
	__u8	mtl;
	__u8	tnvmcap[16];
	__u8	rsvd37[27];
};

/**
 * struct nvme_mi_vpd_ppmra -
 * @nppmravn:
 * @pn:
 * @ppi:
 * @ls:
 * @mlw:
 * @mctp:
 * @refccap:
 * @pi:
 */
struct nvme_mi_vpd_ppmra {
	__u8	nppmravn;
	__u8	pn;
	__u8	ppi;
	__u8	ls;
	__u8	mlw;
	__u8	mctp;
	__u8	refccap;
	__u8	pi;
	__u8	rsvd13[3];
};

/**
 * struct nvme_mi_vpd_telem -
 * @type:
 * @rev:
 * @len:
 * @data:
 */
struct nvme_mi_vpd_telem {
	__u8	type;
	__u8	rev;
	__u8	len;
	__u8	data[0];
};

/**
 * enum -
 * @NVME_MI_ELEM_EED:
 * @NVME_MI_ELEM_USCE:
 * @NVME_MI_ELEM_ECED:
 * @NVME_MI_ELEM_LED:
 * @NVME_MI_ELEM_SMBMED:
 * @NVME_MI_ELEM_PCIESED:
 * @NVME_MI_ELEM_NVMED:
 */
enum {
	NVME_MI_ELEM_EED	= 1,
	NVME_MI_ELEM_USCE	= 2,
	NVME_MI_ELEM_ECED	= 3,
	NVME_MI_ELEM_LED	= 4,
	NVME_MI_ELEM_SMBMED	= 5,
	NVME_MI_ELEM_PCIESED	= 6,
	NVME_MI_ELEM_NVMED	= 7,
};

/**
 * struct nvme_mi_vpd_tra -
 * @vn:
 * @ec:
 * @elems:
 */
struct nvme_mi_vpd_tra {
	__u8	vn;
	__u8	rsvd6;
	__u8	ec;
	struct nvme_mi_vpd_telem elems[0];
};

/**
 * struct nvme_mi_vpd_mr_common -
 * @type:
 * @rf:
 * @rlen:
 * @rchksum:
 * @hchksum:
 * @nmra:
 * @ppmra:
 * @tmra:
 */
struct nvme_mi_vpd_mr_common {
	__u8	type;
	__u8	rf;
	__u8	rlen;
	__u8	rchksum;
	__u8	hchksum;

	union {
		struct nvme_mi_vpd_mra nmra;
		struct nvme_mi_vpd_ppmra ppmra;
		struct nvme_mi_vpd_tra tmra;
	};
};

/**
 * struct nvme_mi_vpd_hdr -
 * @ipmiver:
 * @iuaoff:
 * @ciaoff:
 * @biaoff:
 * @piaoff:
 * @mrioff:
 * @chchk:
 * @vpd:
 */
struct nvme_mi_vpd_hdr {
	__u8	ipmiver;
	__u8	iuaoff;
	__u8	ciaoff;
	__u8	biaoff;
	__u8	piaoff;
	__u8	mrioff;
	__u8	rsvd6;
	__u8	chchk;
	__u8	vpd[];
};

/**
 * enum nvme_status_field - Defines all parts of the nvme status field: status
 * 			    code, status code type, and additional flags.
 * @NVME_SCT_MASK:		      Mask to get the value of the Status Code Type
 * @NVME_SCT_GENERIC:		      Generic errors applicable to multiple opcodes
 * @NVME_SCT_CMD_SPECIFIC:	      Errors associated to a specific opcode
 * @NVME_SCT_MEDIA:		      Errors associated with media and data integrity
 * @NVME_SCT_PATH:		      Errors associated with the paths connection
 * @NVME_SCT_VS:		      Vendor specific errors
 * @NVME_SC_MASK:		      Mask to get the value of the status code.
 * @NVME_SC_SUCCESS:		      Successful Completion: The command
 * 				      completed without error.
 * @NVME_SC_INVALID_OPCODE:	      Invalid Command Opcode: A reserved coded
 * 				      value or an unsupported value in the
 * 				      command opcode field.
 * @NVME_SC_INVALID_FIELD:	      Invalid Field in Command: A reserved
 * 				      coded value or an unsupported value in a
 * 				      defined field.
 * @NVME_SC_CMDID_CONFLICT:	      Command ID Conflict: The command
 * 				      identifier is already in use.
 * @NVME_SC_DATA_XFER_ERROR:	      Data Transfer Error: Transferring the
 * 				      data or metadata associated with a
 * 				      command experienced an error.
 * @NVME_SC_POWER_LOSS:		      Commands Aborted due to Power Loss
 * 				      Notification: Indicates that the command
 * 				      was aborted due to a power loss
 * 				      notification.
 * @NVME_SC_INTERNAL:		      Internal Error: The command was not
 * 				      completed successfully due to an internal error.
 * @NVME_SC_ABORT_REQ:		      Command Abort Requested: The command was
 * 				      aborted due to an Abort command being
 * 				      received that specified the Submission
 * 				      Queue Identifier and Command Identifier
 * 				      of this command.
 * @NVME_SC_ABORT_QUEUE:	      Command Aborted due to SQ Deletion: The
 * 				      command was aborted due to a Delete I/O
 * 				      Submission Queue request received for the
 * 				      Submission Queue to which the command was
 * 				      submitted.
 * @NVME_SC_FUSED_FAIL:		      Command Aborted due to Failed Fused Command:
 * 				      The command was aborted due to the other
 * 				      command in a fused operation failing.
 * @NVME_SC_FUSED_MISSING:	      Aborted due to Missing Fused Command: The
 * 				      fused command was aborted due to the
 * 				      adjacent submission queue entry not
 * 				      containing a fused command that is the
 * 				      other command.
 * @NVME_SC_INVALID_NS:		      Invalid Namespace or Format: The
 * 				      namespace or the format of that namespace
 * 				      is invalid.
 * @NVME_SC_CMD_SEQ_ERROR:	      Command Sequence Error: The command was
 * 				      aborted due to a protocol violation in a
 * 				      multi-command sequence.
 * @NVME_SC_SGL_INVALID_LAST:	      Invalid SGL Segment Descriptor: The
 * 				      command includes an invalid SGL Last
 * 				      Segment or SGL Segment descriptor.
 * @NVME_SC_SGL_INVALID_COUNT:	      Invalid Number of SGL Descriptors: There
 * 				      is an SGL Last Segment descriptor or an
 * 				      SGL Segment descriptor in a location
 * 				      other than the last descriptor of a
 * 				      segment based on the length indicated.
 * @NVME_SC_SGL_INVALID_DATA:	      Data SGL Length Invalid: This may occur
 * 				      if the length of a Data SGL is too short.
 * 				      This may occur if the length of a Data
 * 				      SGL is too long and the controller does
 * 				      not support SGL transfers longer than the
 * 				      amount of data to be transferred as
 * 				      indicated in the SGL Support field of the
 * 				      Identify Controller data structure.
 * @NVME_SC_SGL_INVALID_METADATA:     Metadata SGL Length Invalid: This may
 * 				      occur if the length of a Metadata SGL is
 * 				      too short. This may occur if the length
 * 				      of a Metadata SGL is too long and the
 * 				      controller does not support SGL transfers
 * 				      longer than the amount of data to be
 * 				      transferred as indicated in the SGL
 * 				      Support field of the Identify Controller
 * 				      data structure.
 * @NVME_SC_SGL_INVALID_TYPE:	      SGL Descriptor Type Invalid: The type of
 * 				      an SGL Descriptor is a type that is not
 * 				      supported by the controller.
 * @NVME_SC_CMB_INVALID_USE:	      Invalid Use of Controller Memory Buffer:
 * 				      The attempted use of the Controller
 * 				      Memory Buffer is not supported by the
 * 				      controller.
 * @NVME_SC_PRP_INVALID_OFFSET:       PRP Offset Invalid: The Offset field for
 * 				      a PRP entry is invalid.
 * @NVME_SC_AWU_EXCEEDED:	      Atomic Write Unit Exceeded: The length
 * 				      specified exceeds the atomic write unit size.
 * @NVME_SC_OP_DENIED:		      Operation Denied: The command was denied
 * 				      due to lack of access rights. Refer to
 * 				      the appropriate security specification.
 * @NVME_SC_SGL_INVALID_OFFSET:	      SGL Offset Invalid: The offset specified
 * 				      in a descriptor is invalid. This may
 * 				      occur when using capsules for data
 * 				      transfers in NVMe over Fabrics
 * 				      implementations and an invalid offset in
 * 				      the capsule is specified.
 * @NVME_SC_HOSTID_FORMAT:	      Host Identifier Inconsistent Format: The
 * 				      NVM subsystem detected the simultaneous
 * 				      use of 64- bit and 128-bit Host
 * 				      Identifier values on different
 * 				      controllers.
 * @NVME_SC_KAT_EXPIRED:	      Keep Alive Timer Expired: The Keep Alive
 * 				      Timer expired.
 * @NVME_SC_KAT_INVALID:	      Keep Alive Timeout Invalid: The Keep
 * 				      Alive Timeout value specified is invalid.
 * @NVME_SC_CMD_ABORTED_PREMEPT:      Command Aborted due to Preempt and Abort:
 * 				      The command was aborted due to a
 * 				      Reservation Acquire command.
 * @NVME_SC_SANITIZE_FAILED:	      Sanitize Failed: The most recent sanitize
 * 				      operation failed and no recovery action
 * 				      has been successfully completed.
 * @NVME_SC_SANITIZE_IN_PROGRESS:     Sanitize In Progress: The requested
 * 				      function (e.g., command) is prohibited
 * 				      while a sanitize operation is in
 * 				      progress.
 * @NVME_SC_SGL_INVALID_GRANULARITY:  SGL Data Block Granularity Invalid: The
 * 				      Address alignment or Length granularity
 * 				      for an SGL Data Block descriptor is
 * 				      invalid.
 * @NVME_SC_CMD_IN_CMBQ_NOT_SUPP:     Command Not Supported for Queue in CMB:
 * 				      The implementation does not support
 * 				      submission of the command to a Submission
 * 				      Queue in the Controller Memory Buffer or
 * 				      command completion to a Completion Queue
 * 				      in the Controller Memory Buffer.
 * @NVME_SC_NS_WRITE_PROTECTED:	      Namespace is Write Protected: The command
 * 				      is prohibited while the namespace is
 * 				      write protected as a result of a change
 * 				      in the namespace write protection state
 * 				      as defined by the Namespace Write
 * 				      Protection State Machine.
 * @NVME_SC_CMD_INTERRUPTED:	      Command Interrupted: Command processing
 * 				      was interrupted and the controller is
 * 				      unable to successfully complete the
 * 				      command. The host should retry the
 * 				      command.
 * @NVME_SC_TRAN_TPORT_ERROR:	      Transient Transport Error: A transient
 * 				      transport error was detected. If the
 * 				      command is retried on the same
 * 				      controller, the command is likely to
 * 				      succeed. A command that fails with a
 * 				      transient transport error four or more
 * 				      times should be treated as a persistent
 * 				      transport error that is not likely to
 * 				      succeed if retried on the same
 * 				      controller.
 * @NVME_SC_LBA_RANGE:		      LBA Out of Range: The command references
 * 				      an LBA that exceeds the size of the namespace.
 * @NVME_SC_CAP_EXCEEDED:	      Capacity Exceeded: Execution of the
 * 				      command has caused the capacity of the
 * 				      namespace to be exceeded.
 * @NVME_SC_NS_NOT_READY:	      Namespace Not Ready: The namespace is not
 * 				      ready to be accessed as a result of a
 * 				      condition other than a condition that is
 * 				      reported as an Asymmetric Namespace
 * 				      Access condition.
 * @NVME_SC_RESERVATION_CONFLICT:     Reservation Conflict: The command was
 * 				      aborted due to a conflict with a
 * 				      reservation held on the accessed
 * 				      namespace.
 * @NVME_SC_FORMAT_IN_PROGRESS:	      Format In Progress: A Format NVM command
 * 				      is in progress on the namespace.
 * @NVME_SC_CQ_INVALID:		      Completion Queue Invalid: The Completion
 * 				      Queue identifier specified in the command
 * 				      does not exist.
 * @NVME_SC_QID_INVALID:	      Invalid Queue Identifier: The creation of
 *				      the I/O Completion Queue failed due to an
 *				      invalid queue identifier specified as
 *				      part of the command. An invalid queue
 *				      identifier is one that is currently in
 *				      use or one that is outside the range
 *				      supported by the controller.
 * @NVME_SC_QUEUE_SIZE:		      Invalid Queue Size: The host attempted to
 * 				      create an I/O Completion Queue with an
 * 				      invalid number of entries.
 * @NVME_SC_ABORT_LIMIT:	      Abort Command Limit Exceeded: The number
 * of concurrently outstanding Abort commands has exceeded the limit indicated
 * 				      in the Identify Controller data
 * 				      structure.
 * @NVME_SC_ABORT_MISSING:	      Abort Command is missing: The abort
 * 				      command is missing.
 * @NVME_SC_ASYNC_LIMIT:	      Asynchronous Event Request Limit
 * 				      Exceeded: The number of concurrently
 * 				      outstanding Asynchronous Event Request
 * 				      commands has been exceeded.
 * @NVME_SC_FIRMWARE_SLOT:	      Invalid Firmware Slot: The firmware slot
 * 				      indicated is invalid or read only. This
 * 				      error is indicated if the firmware slot
 * 				      exceeds the number supported.
 * @NVME_SC_FIRMWARE_IMAGE:	      Invalid Firmware Image: The firmware
 * 				      image specified for activation is invalid
 * 				      and not loaded by the controller.
 * @NVME_SC_INVALID_VECTOR:	      Invalid Interrupt Vector: The creation of
 * 				      the I/O Completion Queue failed due to an
 * 				      invalid interrupt vector specified as
 * 				      part of the command.
 * @NVME_SC_INVALID_LOG_PAGE:	      Invalid Log Page: The log page indicated
 * 				      is invalid. This error condition is also
 * 				      returned if a reserved log page is
 * 				      requested.
 * @NVME_SC_INVALID_FORMAT:	      Invalid Format: The LBA Format specified
 * 				      is not supported.
 * @NVME_SC_FW_NEEDS_CONV_RESET:      Firmware Activation Requires Conventional Reset:
 * 				      The firmware commit was successful,
 * 				      however, activation of the firmware image
 * 				      requires a conventional reset.
 * @NVME_SC_INVALID_QUEUE:	      Invalid Queue Deletion: Invalid I/O
 * 				      Completion Queue specified to delete.
 * @NVME_SC_FEATURE_NOT_SAVEABLE:     Feature Identifier Not Saveable: The
 * 				      Feature Identifier specified does not
 * 				      support a saveable value.
 * @NVME_SC_FEATURE_NOT_CHANGEABLE:   Feature Not Changeable: The Feature
 * 				      Identifier is not able to be changed.
 * @NVME_SC_FEATURE_NOT_PER_NS:	      Feature Not Namespace Specific: The
 * 				      Feature Identifier specified is not
 * 				      namespace specific. The Feature
 * 				      Identifier settings apply across all
 * 				      namespaces.
 * @NVME_SC_FW_NEEDS_SUBSYS_RESET:    Firmware Activation Requires NVM
 * 				      Subsystem Reset: The firmware commit was
 * 				      successful, however, activation of the
 * 				      firmware image requires an NVM Subsystem.
 * @NVME_SC_FW_NEEDS_RESET:	      Firmware Activation Requires Controller
 * 				      Level Reset: The firmware commit was
 * 				      successful; however, the image specified
 * 				      does not support being activated without
 * 				      a reset.
 * @NVME_SC_FW_NEEDS_MAX_TIME:	      Firmware Activation Requires Maximum Time
 * 				      Violation: The image specified if
 * 				      activated immediately would exceed the
 * 				      Maximum Time for Firmware Activation
 * 				      (MTFA) value reported in Identify
 * 				      Controller.
 * @NVME_SC_FW_ACTIVATE_PROHIBITED:   Firmware Activation Prohibited: The image
 * 				      specified is being prohibited from
 * 				      activation by the controller for vendor
 * 				      specific reasons.
 * @NVME_SC_OVERLAPPING_RANGE:	      Overlapping Range: The downloaded
 * 				      firmware image has overlapping ranges.
 * @NVME_SC_NS_INSUFFICIENT_CAP:      Namespace Insufficient Capacity: Creating
 * 				      the namespace requires more free space
 * 				      than is currently available.
 * @NVME_SC_NS_ID_UNAVAILABLE:	      Namespace Identifier Unavailable: The
 * 				      number of namespaces supported has been
 * 				      exceeded.
 * @NVME_SC_NS_ALREADY_ATTACHED:      Namespace Already Attached: The
 * 				      controller is already attached to the
 * 				      namespace specified.
 * @NVME_SC_NS_IS_PRIVATE:	      Namespace Is Private: The namespace is
 * 				      private and is already attached to one
 * 				      controller.
 * @NVME_SC_NS_NOT_ATTACHED:	      Namespace Not Attached: The request to
 * 				      detach the controller could not be
 * 				      completed because the controller is not
 * 				      attached to the namespace.
 * @NVME_SC_THIN_PROV_NOT_SUPP:	      Thin Provisioning Not Supported: Thin
 * 				      provisioning is not supported by the
 * 				      controller.
 * @NVME_SC_CTRL_LIST_INVALID:	      Controller List Invalid: The controller
 * 				      list provided contains invalid controller
 * 				      ids.
 * @NVME_SC_SELF_TEST_IN_PROGRESS:    Device Self-test In Progress:
 * @NVME_SC_BP_WRITE_PROHIBITED:      Boot Partition Write Prohibited: The
 * 				      command is trying to modify a locked Boot
 * 				      Partition.
 * @NVME_SC_INVALID_CTRL_ID:	      Invalid Controller Identifier:
 * @NVME_SC_INVALID_SEC_CTRL_STATE:   Invalid Secondary Controller State
 * @NVME_SC_INVALID_CTRL_RESOURCES:   Invalid Number of Controller Resources
 * @NVME_SC_INVALID_RESOURCE_ID:      Invalid Resource Identifier
 * @NVME_SC_PMR_SAN_PROHIBITED:	      Sanitize Prohibited While Persistent
 * 				      Memory Region is Enabled
 * @NVME_SC_ANA_GROUP_ID_INVALID:     ANA Group Identifier Invalid
 * @NVME_SC_ANA_ATTACH_FAILED:	      ANA Attach Failed
 * @NVME_SC_BAD_ATTRIBUTES:	      Conflicting Dataset Management Attributes
 * @NVME_SC_INVALID_PI:		      Invalid Protection Information
 * @NVME_SC_READ_ONLY:		      Attempted Write to Read Only Range
 * @NVME_SC_CONNECT_FORMAT:	      Incompatible Format: The NVM subsystem
 * 				      does not support the record format
 * 				      specified by the host.
 * @NVME_SC_CONNECT_CTRL_BUSY:	      Controller Busy: The controller is
 * 				      already associated with a host.
 * @NVME_SC_CONNECT_INVALID_PARAM:    Connect Invalid Parameters: One or more
 * 				      of the command parameters.
 * @NVME_SC_CONNECT_RESTART_DISC:     Connect Restart Discovery: The NVM
 * 				      subsystem requested is not available.
 * @NVME_SC_CONNECT_INVALID_HOST:     Connect Invalid Host: The host is either
 * 				      not allowed to establish an association
 * 				      to any controller in the NVM subsystem or
 * 				      the host is not allowed to establish an
 * 				      association to the specified controller
 * @NVME_SC_DISCONNECT_INVALID_QTYPE: Invalid Queue Type: The command was sent
 * 				      on the wrong queue type.
 * @NVME_SC_DISCOVERY_RESTART:	      Discover Restart: The snapshot of the
 * 				      records is now invalid or out of date.
 * @NVME_SC_AUTH_REQUIRED:	      Authentication Required: NVMe in-band
 * 				      authentication is required and the queue
 * 				      has not yet been authenticated.
 * @NVME_SC_WRITE_FAULT:	      Write Fault: The write data could not be
 * 				      committed to the media.
 * @NVME_SC_READ_ERROR:		      Unrecovered Read Error: The read data
 * 				      could not be recovered from the media.
 * @NVME_SC_GUARD_CHECK:	      End-to-end Guard Check Error: The command
 * 				      was aborted due to an end-to-end guard
 * 				      check failure.
 * @NVME_SC_APPTAG_CHECK:	      End-to-end Application Tag Check Error:
 * 				      The command was aborted due to an
 * 				      end-to-end application tag check failure.
 * @NVME_SC_REFTAG_CHECK:	      End-to-end Reference Tag Check Error: The
 * 				      command was aborted due to an end-to-end
 * 				      reference tag check failure.
 * @NVME_SC_COMPARE_FAILED:	      Compare Failure: The command failed due
 * 				      to a miscompare during a Compare command.
 * @NVME_SC_ACCESS_DENIED:	      Access Denied: Access to the namespace
 * 				      and/or LBA range is denied due to lack of
 * 				      access rights.
 * @NVME_SC_UNWRITTEN_BLOCK:	      Deallocated or Unwritten Logical Block:
 * 				      The command failed due to an attempt to
 * 				      read from or verify an LBA range
 * 				      containing a deallocated or unwritten
 * 				      logical block.
 * @NVME_SC_ANA_INTERNAL_PATH_ERROR:  Internal Path Error: The command was not
 * 				      completed as the result of a controller
 * 				      internal error that is specific to the
 * 				      controller processing the command.
 * @NVME_SC_ANA_PERSISTENT_LOSS:      Asymmetric Access Persistent Loss: The
 * 				      requested function (e.g., command) is not
 * 				      able to be performed as a result of the
 * 				      relationship between the controller and
 * 				      the namespace being in the ANA Persistent
 * 				      Loss state.
 * @NVME_SC_ANA_INACCESSIBLE:	      Asymmetric Access Inaccessible: The
 * 				      requested function (e.g., command) is not
 * 				      able to be performed as a result of the
 * 				      relationship between the controller and
 * 				      the namespace being in the ANA
 * 				      Inaccessible state.
 * @NVME_SC_ANA_TRANSITION:	      Asymmetric Access Transition: The
 * 				      requested function (e.g., command) is not
 * 				      able to be performed as a result of the
 * 				      relationship between the controller and
 * 				      the namespace transitioning between
 * 				      Asymmetric Namespace Access states.
 * @NVME_SC_CTRL_PATH_ERROR:	      Controller Pathing Error: A pathing error
 * 				      was detected by the controller.
 * @NVME_SC_HOST_PATH_ERROR:	      Host Pathing Error: A pathing error was
 * 				      detected by the host.
 * @NVME_SC_CMD_ABORTED_BY_HOST:      Command Aborted By Host: The command was
 * 				      aborted as a result of host action.
 * @NVME_SC_CRD:		      Mask to get value of Command Retry Delay
 * 				      index
 * @NVME_SC_MORE:		      More bit. If set, more status information
 * 				      for this command as part of the Error
 * 				      Information log that may be retrieved with
 * 				      the Get Log Page command.
 * @NVME_SC_DNR:		      Do Not Retry bit. If set, if the same
 * 				      command is re-submitted to any controller
 * 				      in the NVM subsystem, then that
 * 				      re-submitted command is expected to fail.
 */
enum nvme_status_field {
	/*
	 * Status Code Type indicators
	 */
	NVME_SCT_MASK			= 0x700,
	NVME_SCT_SHIFT			= 0x700,
	NVME_SCT_GENERIC		= 0x000,
	NVME_SCT_CMD_SPECIFIC		= 0x100,
	NVME_SCT_MEDIA			= 0x200,
	NVME_SCT_PATH			= 0x300,
	NVME_SCT_VS			= 0x700,

	/*
	 * Status Code inidicators
	 */
	NVME_SC_MASK			= 0xff,

	/*
	 * Generic Command Status Codes:
	 */
	NVME_SC_SUCCESS			= 0x0,
	NVME_SC_INVALID_OPCODE		= 0x1,
	NVME_SC_INVALID_FIELD		= 0x2,
	NVME_SC_CMDID_CONFLICT		= 0x3,
	NVME_SC_DATA_XFER_ERROR		= 0x4,
	NVME_SC_POWER_LOSS		= 0x5,
	NVME_SC_INTERNAL		= 0x6,
	NVME_SC_ABORT_REQ		= 0x7,
	NVME_SC_ABORT_QUEUE		= 0x8,
	NVME_SC_FUSED_FAIL		= 0x9,
	NVME_SC_FUSED_MISSING		= 0xa,
	NVME_SC_INVALID_NS		= 0xb,
	NVME_SC_CMD_SEQ_ERROR		= 0xc,
	NVME_SC_SGL_INVALID_LAST	= 0xd,
	NVME_SC_SGL_INVALID_COUNT	= 0xe,
	NVME_SC_SGL_INVALID_DATA	= 0xf,
	NVME_SC_SGL_INVALID_METADATA	= 0x10,
	NVME_SC_SGL_INVALID_TYPE	= 0x11,
	NVME_SC_CMB_INVALID_USE		= 0x12,
	NVME_SC_PRP_INVALID_OFFSET	= 0x13,
	NVME_SC_AWU_EXCEEDED		= 0x14,
	NVME_SC_OP_DENIED		= 0x15,
	NVME_SC_SGL_INVALID_OFFSET	= 0x16,
	NVME_SC_HOSTID_FORMAT		= 0x18,
	NVME_SC_KAT_EXPIRED		= 0x19,
	NVME_SC_KAT_INVALID		= 0x1a,
	NVME_SC_CMD_ABORTED_PREMEPT	= 0x1b,
	NVME_SC_SANITIZE_FAILED		= 0x1c,
	NVME_SC_SANITIZE_IN_PROGRESS	= 0x1d,
	NVME_SC_SGL_INVALID_GRANULARITY	= 0x1e,
	NVME_SC_CMD_IN_CMBQ_NOT_SUPP	= 0x1f,
	NVME_SC_NS_WRITE_PROTECTED	= 0x20,
	NVME_SC_CMD_INTERRUPTED		= 0x21,
	NVME_SC_TRAN_TPORT_ERROR	= 0x22,
	NVME_SC_LBA_RANGE		= 0x80,
	NVME_SC_CAP_EXCEEDED		= 0x81,
	NVME_SC_NS_NOT_READY		= 0x82,
	NVME_SC_RESERVATION_CONFLICT	= 0x83,
	NVME_SC_FORMAT_IN_PROGRESS	= 0x84,

	/*
	 * Command Specific Status Codes:
	 */
	NVME_SC_CQ_INVALID		= 0x00,
	NVME_SC_QID_INVALID		= 0x01,
	NVME_SC_QUEUE_SIZE		= 0x02,
	NVME_SC_ABORT_LIMIT		= 0x03,
	NVME_SC_ABORT_MISSING		= 0x04,
	NVME_SC_ASYNC_LIMIT		= 0x05,
	NVME_SC_FIRMWARE_SLOT		= 0x06,
	NVME_SC_FIRMWARE_IMAGE		= 0x07,
	NVME_SC_INVALID_VECTOR		= 0x08,
	NVME_SC_INVALID_LOG_PAGE	= 0x09,
	NVME_SC_INVALID_FORMAT		= 0x0a,
	NVME_SC_FW_NEEDS_CONV_RESET	= 0x0b,
	NVME_SC_INVALID_QUEUE		= 0x0c,
	NVME_SC_FEATURE_NOT_SAVEABLE	= 0x0d,
	NVME_SC_FEATURE_NOT_CHANGEABLE	= 0x0e,
	NVME_SC_FEATURE_NOT_PER_NS	= 0x0f,
	NVME_SC_FW_NEEDS_SUBSYS_RESET	= 0x10,
	NVME_SC_FW_NEEDS_RESET		= 0x11,
	NVME_SC_FW_NEEDS_MAX_TIME	= 0x12,
	NVME_SC_FW_ACTIVATE_PROHIBITED	= 0x13,
	NVME_SC_OVERLAPPING_RANGE	= 0x14,
	NVME_SC_NS_INSUFFICIENT_CAP	= 0x15,
	NVME_SC_NS_ID_UNAVAILABLE	= 0x16,
	NVME_SC_NS_ALREADY_ATTACHED	= 0x18,
	NVME_SC_NS_IS_PRIVATE		= 0x19,
	NVME_SC_NS_NOT_ATTACHED		= 0x1a,
	NVME_SC_THIN_PROV_NOT_SUPP	= 0x1b,
	NVME_SC_CTRL_LIST_INVALID	= 0x1c,
	NVME_SC_SELF_TEST_IN_PROGRESS	= 0x1d,
	NVME_SC_BP_WRITE_PROHIBITED	= 0x1e,
	NVME_SC_INVALID_CTRL_ID		= 0x1f,
	NVME_SC_INVALID_SEC_CTRL_STATE	= 0x20,
	NVME_SC_INVALID_CTRL_RESOURCES	= 0x21,
	NVME_SC_INVALID_RESOURCE_ID	= 0x22,
	NVME_SC_PMR_SAN_PROHIBITED	= 0x23,
	NVME_SC_ANA_GROUP_ID_INVALID	= 0x24,
	NVME_SC_ANA_ATTACH_FAILED	= 0x25,

	/*
	 * I/O Command Set Specific - NVM commands:
	 */
	NVME_SC_BAD_ATTRIBUTES		= 0x80,
	NVME_SC_INVALID_PI		= 0x81,
	NVME_SC_READ_ONLY		= 0x82,

	/*
	 * I/O Command Set Specific - Fabrics commands:
	 */
	NVME_SC_CONNECT_FORMAT		= 0x80,
	NVME_SC_CONNECT_CTRL_BUSY	= 0x81,
	NVME_SC_CONNECT_INVALID_PARAM	= 0x82,
	NVME_SC_CONNECT_RESTART_DISC	= 0x83,
	NVME_SC_CONNECT_INVALID_HOST	= 0x84,
	NVME_SC_DISCONNECT_INVALID_QTYPE= 0x85,
	NVME_SC_DISCOVERY_RESTART	= 0x90,
	NVME_SC_AUTH_REQUIRED		= 0x91,

	/*
	 * Media and Data Integrity Errors:
	 */
	NVME_SC_WRITE_FAULT		= 0x80,
	NVME_SC_READ_ERROR		= 0x81,
	NVME_SC_GUARD_CHECK		= 0x82,
	NVME_SC_APPTAG_CHECK		= 0x83,
	NVME_SC_REFTAG_CHECK		= 0x84,
	NVME_SC_COMPARE_FAILED		= 0x85,
	NVME_SC_ACCESS_DENIED		= 0x86,
	NVME_SC_UNWRITTEN_BLOCK		= 0x87,

	/*
	 * Path-related Errors:
	 */
	NVME_SC_ANA_INTERNAL_PATH_ERROR	= 0x00,
	NVME_SC_ANA_PERSISTENT_LOSS	= 0x01,
	NVME_SC_ANA_INACCESSIBLE	= 0x02,
	NVME_SC_ANA_TRANSITION		= 0x03,
	NVME_SC_CTRL_PATH_ERROR		= 0x60,
	NVME_SC_HOST_PATH_ERROR		= 0x70,
	NVME_SC_CMD_ABORTED_BY_HOST	= 0x71,

	/*
	 * Additional status field flags
	 */
	NVME_SC_CRD			= 0x1800,
	NVME_SC_MORE			= 0x2000,
	NVME_SC_DNR			= 0x4000,
};

/**
 * nvme_status_code_type() - Returns the NVMe Status Code Type
 * @status_field: The NVMe Completion Queue Entry's Status Field
 *
 * See &enum nvme_status_field
 */
static inline __u16 nvme_status_code_type(__u16 status_field)
{
	return status_field & NVME_SCT_MASK;
}

/**
 * nvme_status_code() - Returns the NVMe Status Code
 * @status_field: The NVMe Completion Queue Entry's Status Field
 *
 * See &enum nvme_status_field
 */
static inline __u16 nvme_status_code(__u16 status_field)
{
	return status_field & NVME_SC_MASK;
}

#define NVME_MAJOR(ver)		((ver) >> 16)
#define NVME_MINOR(ver)		(((ver) >> 8) & 0xff)
#define NVME_TERTIARY(ver)	((ver) & 0xff)

#endif /* _LIBNVME_TYPES_H */
