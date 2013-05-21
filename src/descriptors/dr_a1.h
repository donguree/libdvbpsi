#ifndef _DVBPSI_DR_a1_H_
#define _DVBPSI_DR_a1_H_

#ifdef __cplusplus
extern "C"
{
#endif


  typedef struct dvbpsi_service_location_element_s
  {
    uint8_t i_stream_type;
    uint16_t i_elementary_pid;
    char i_iso_639_code[3];
  } dvbpsi_service_location_element_t;

/*****************************************************************************
 * dvbpsi_service_location_dr_s
 *****************************************************************************/
/*!
 * \struct dvbpsi_service_dr_s
 * \brief "service" descriptor structure.
 *
 * This structure is used to store a decoded "service location"
 * descriptor.
 */
/*!
 * \typedef struct dvbpsi_service_location_dr_s dvbpsi_service_location_dr_t
 * \brief dvbpsi_service_dr_t type definition.
 */
  typedef struct dvbpsi_service_location_dr_s
  {
    uint16_t i_pcr_pid;		/*!< PCR_PID */
    uint8_t i_number_elements;	/*!< number of elements used for this service */

    dvbpsi_service_location_element_t elements[0xff];

  } dvbpsi_service_location_dr_t;


/*****************************************************************************
 * dvbpsi_DecodeServiceDataDr
 *****************************************************************************/
/*!
 * \fn dvbpsi_service_dr_t * dvbpsi_DecodeServiceLocationDr(
                                        dvbpsi_descriptor_t * p_descriptor)
 * \brief "service location" descriptor decoder.
 * \param p_descriptor pointer to the descriptor structure
 * \return a pointer to a new "service" descriptor structure
 * which contains the decoded data.
 */
  dvbpsi_service_location_dr_t
    *dvbpsi_DecodeServiceLocationDr (dvbpsi_descriptor_t * p_descriptor);

#if 0
/*****************************************************************************
 * dvbpsi_GenServiceDataDr
 *****************************************************************************/
/*!
 * \fn dvbpsi_descriptor_t * dvbpsi_GenServiceDr(
                        dvbpsi_service_dr_t * p_decoded, bool b_duplicate)
 * \brief "service" descriptor generator.
 * \param p_decoded pointer to a decoded "service" descriptor
 * structure
 * \param b_duplicate if true then duplicate the p_decoded structure into
 * the descriptor
 * \return a pointer to a new descriptor structure which contains encoded data.
 */
  dvbpsi_descriptor_t *dvbpsi_GenServiceLocationDr (dvbpsi_service_dr_t *
						    p_decoded,
						    bool b_duplicate);
#endif


#ifdef __cplusplus
};
#endif

#else
#error "Multiple inclusions of dr_a1.h"
#endif
