/*
 * fsat-pkt-ana.h
 * 
 * Copyright (C) 2017, Federal University of Santa Catarina.
 * 
 * This file is part of FloripaSat-Packet-Analyzer.
 * 
 * FloripaSat-Packet-Analyzer is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * FloripaSat-Packet-Analyzer is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with FloripaSat-Packet-Analyzer.
 * If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \file fsat-pkt-ana.h
 * 
 * \brief .
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 1.2
 * 
 * \date 10/09/2017
 * 
 * \defgroup fsat_pkt_ana FloripaSat Packet Analyzer
 * \{
 */

#ifndef FSAT_PKT_ANA_H_
#define FSAT_PKT_ANA_H_

#include <gtkmm.h>
#include <vector>
#include <stdint.h>

#include "uart.h"
#include "event_log.h"
#include "log.h"
#include "protocol_statistic.h"
#include "packet_data.h"
#include "ngham_pkts.h"

#define FSAT_PKT_ANA_DEFAULT_UI_FILE    "glade/MainWindow.glade"

#define DATA_RECEPTION_SAMPLE_RATE      1000

/**
 * \class FSatPktAna
 * 
 * \brief 
 */
class FSatPktAna
{
        // Main window
        Gtk::Window                     *main_window;
        
        // Toolbar
        Gtk::ToolButton                 *toolbutton_open_log_file;
        Gtk::ToolButton                 *toolbutton_config;
        Gtk::ToolButton                 *toolbutton_statistics;
        Gtk::ToolButton                 *toolbutton_gnuradio;
        Gtk::ToolButton                 *toolbutton_about;
        
        // Beacon stream
        Gtk::FileChooserButton          *filechooserbutton_beacon;
        Gtk::ToggleButton               *togglebutton_play_beacon;
        Gtk::ToggleButton               *togglebutton_pause_beacon;
        Gtk::Button                     *button_stop_beacon;
        Gtk::Button                     *button_clear_all_beacon;
        
        // Telemetry stream
        Gtk::FileChooserButton          *filechooserbutton_telemetry;
        Gtk::ToggleButton               *togglebutton_play_telemetry;
        Gtk::ToggleButton               *togglebutton_pause_telemetry;
        Gtk::Button                     *button_stop_telemetry;
        Gtk::Button                     *button_clear_all_telemetry;
        
        // Log
        Gtk::CheckButton                *checkbutton_log_ngham_packets;
        Gtk::CheckButton                *checkbutton_log_ax25_packets;
        Gtk::CheckButton                *checkbutton_log_beacon_data;
        Gtk::CheckButton                *checkbutton_log_telemetry_data;
        
        // Serial Port
        Gtk::Entry                      *entry_serial_port;
        Gtk::ComboBox                   *combobox_baudrate;
        Gtk::ToggleButton               *togglebutton_open_close_port;
        
        // Event log
        Gtk::TextView                   *textview_event_log;
        
        // NGHam Preamble
        Gtk::Entry                      *entry_ngham_config_preamble_byte;
        Gtk::Entry                      *entry_ngham_config_preamble_quant;
        
        // NGHam Sync. Bytes
        Gtk::Entry                      *entry_ngham_sync_bytes_s0;
        Gtk::Entry                      *entry_ngham_sync_bytes_s1;
        Gtk::Entry                      *entry_ngham_sync_bytes_s2;
        Gtk::Entry                      *entry_ngham_sync_bytes_s3;
        
        // AX25 Preamble
        Gtk::Entry                      *entry_ax25_config_preamble_byte;
        Gtk::Entry                      *entry_ax25_config_preamble_quant;
        
        // AX25 Sync. Bytes
        Gtk::Entry                      *entry_ax25_sync_bytes_s0;
        Gtk::Entry                      *entry_ax25_sync_bytes_s1;
        Gtk::Entry                      *entry_ax25_sync_bytes_s2;
        Gtk::Entry                      *entry_ax25_sync_bytes_s3;
        
        // NGHam Statistics
        Gtk::Label                      *label_ngham_valid_value;
        Gtk::Label                      *label_ngham_invalid_value;
        Gtk::Label                      *label_ngham_total_value;
        Gtk::Label                      *label_ngham_lost_value;
        
        // AX25 Statistics
        Gtk::Label                      *label_ax25_valid_value;
        Gtk::Label                      *label_ax25_invalid_value;
        Gtk::Label                      *label_ax25_total_value;
        Gtk::Label                      *label_ax25_lost_value;
        
        // Beacon Data
        Gtk::Label                      *label_beacon_data_bat1_v_value;
        Gtk::Label                      *label_beacon_data_bat2_v_value;
        Gtk::Label                      *label_beacon_data_bat1_t_value;
        Gtk::Label                      *label_beacon_data_bat2_t_value;
        Gtk::Label                      *label_beacon_data_bat_c_value;
        Gtk::Label                      *label_beacon_data_sp_i_my;
        Gtk::Label                      *label_beacon_data_sp_i_px;
        Gtk::Label                      *label_beacon_data_sp_i_mx;
        Gtk::Label                      *label_beacon_data_sp_i_pz;
        Gtk::Label                      *label_beacon_data_sp_i_mz;
        Gtk::Label                      *label_beacon_data_sp_i_py;
        Gtk::Label                      *label_beacon_data_sp_v_mypx;
        Gtk::Label                      *label_beacon_data_sp_v_mxpz;
        Gtk::Label                      *label_beacon_data_sp_v_mzpy;
        Gtk::Label                      *label_beacon_data_status_energy_level;
        Gtk::Label                      *label_beacon_data_status_imu;
        Gtk::Label                      *label_beacon_data_status_usd;
        Gtk::Label                      *label_beacon_data_status_rush;
        Gtk::Label                      *label_beacon_data_status_eps;
        Gtk::Label                      *label_beacon_data_status_antenna;
        Gtk::Label                      *label_beacon_data_imu_accel_x;
        Gtk::Label                      *label_beacon_data_imu_accel_y;
        Gtk::Label                      *label_beacon_data_imu_accel_z;
        Gtk::Label                      *label_beacon_data_imu_gyro_x;
        Gtk::Label                      *label_beacon_data_imu_gyro_y;
        Gtk::Label                      *label_beacon_data_imu_gyro_z;
        Gtk::Label                      *label_beacon_data_obdh_rst_value;
        Gtk::Label                      *label_beacon_data_system_time_value;
        
        // Telemetry Data
        Gtk::Label                      *label_telemetry_data_status_reset_counter;
        Gtk::Label                      *label_telemetry_data_status_reset_cause;
        Gtk::Label                      *label_telemetry_data_status_clock;
        Gtk::Label                      *label_telemetry_data_status_imu;
        Gtk::Label                      *label_telemetry_data_status_usd;
        Gtk::Label                      *label_telemetry_data_status_rush;
        Gtk::Label                      *label_telemetry_data_status_eps;
        Gtk::Label                      *label_telemetry_data_status_antenna;
        Gtk::Label                      *label_telemetry_data_uc_temp;
        Gtk::Label                      *label_telemetry_data_uc_voltage;
        Gtk::Label                      *label_telemetry_data_uc_current;
        Gtk::Label                      *label_telemetry_data_time_system;
        Gtk::Label                      *label_telemetry_data_time_system_up;
        Gtk::Label                      *label_telemetry_data_imu_accel_x;
        Gtk::Label                      *label_telemetry_data_imu_accel_y;
        Gtk::Label                      *label_telemetry_data_imu_accel_z;
        Gtk::Label                      *label_telemetry_data_imu_gyro_x;
        Gtk::Label                      *label_telemetry_data_imu_gyro_y;
        Gtk::Label                      *label_telemetry_data_imu_gyro_z;
        Gtk::Label                      *label_telemetry_data_sp_sun_p1;
        Gtk::Label                      *label_telemetry_data_sp_sun_p2;
        Gtk::Label                      *label_telemetry_data_sp_sun_p3;
        Gtk::Label                      *label_telemetry_data_sp_temp_p1;
        Gtk::Label                      *label_telemetry_data_sp_temp_p2;
        Gtk::Label                      *label_telemetry_data_sp_temp_p3;
        Gtk::Label                      *label_telemetry_data_eps_bat_mean_i;
        Gtk::Label                      *label_telemetry_data_eps_bat_temp;
        Gtk::Label                      *label_telemetry_data_eps_bat_1_volt;
        Gtk::Label                      *label_telemetry_data_eps_bat_2_volt;
        Gtk::Label                      *label_telemetry_data_eps_bat_current;
        Gtk::Label                      *label_telemetry_data_eps_bat_charge;
        Gtk::Label                      *label_telemetry_data_eps_bat_protection;
        Gtk::Label                      *label_telemetry_data_eps_bat_status;
        Gtk::Label                      *label_telemetry_data_eps_bat_cycles;
        Gtk::Label                      *label_telemetry_data_eps_bat_raac;
        Gtk::Label                      *label_telemetry_data_eps_bat_rsac;
        Gtk::Label                      *label_telemetry_data_eps_bat_rarc;
        Gtk::Label                      *label_telemetry_data_eps_bat_rsrc;
        Gtk::Label                      *label_telemetry_data_eps_sp_i_my;
        Gtk::Label                      *label_telemetry_data_eps_sp_i_px;
        Gtk::Label                      *label_telemetry_data_eps_sp_i_mx;
        Gtk::Label                      *label_telemetry_data_eps_sp_i_pz;
        Gtk::Label                      *label_telemetry_data_eps_sp_i_mz;
        Gtk::Label                      *label_telemetry_data_eps_sp_i_py;
        Gtk::Label                      *label_telemetry_data_eps_sp_v_mypx;
        Gtk::Label                      *label_telemetry_data_eps_sp_v_mxpz;
        Gtk::Label                      *label_telemetry_data_eps_sp_v_mzpy;
        Gtk::Label                      *label_telemetry_data_eps_misc_boost_v;
        Gtk::Label                      *label_telemetry_data_eps_misc_main_bus_v;
        Gtk::Label                      *label_telemetry_data_eps_misc_beacon_i;
        Gtk::Label                      *label_telemetry_data_eps_misc_uc_temp;
        Gtk::Label                      *label_telemetry_data_eps_misc_energy_level;
        
        // Telemetry Packets Statistic
        Gtk::Label                      *label_telemetry_pkt_statistic_total;
        Gtk::Label                      *label_telemetry_pkt_statistic_lost;
        
        // Preferences window
        Gtk::Window                     *window_config;
        
        // About Dialog
        Gtk::AboutDialog                *aboutdialog;
        
        // Message Dialog
        Gtk::MessageDialog              *msg_dialog;
        
        /**
         * \brief 
         */
        UART                            *uart;
        /**
         * \brief 
         */
        EventLog                        *event_log;
        /**
         * \brief 
         */
        ProtocolStatistic               *ngham_statistic;
        /**
         * \brief 
         */
        //ProtocolStatistic               *ax25_statistic;
        /**
         * \brief 
         */
        ProtocolStatistic               *telemetry_ngham_statistic;
        /**
         * \brief 
         */
        PacketData                      *beacon_data;
        /**
         * \brief 
         */
        PacketData                      *telemetry_data;
        /**
         * \brief 
         */
        NGHamPkts                       *ngham_pkts_beacon;
        /**
         * \brief 
         */
        //AX25Pkts                        *ax25_pkts_beacon;
        /**
         * \brief 
         */
        NGHamPkts                       *ngham_pkts_telemetry;
        
        /**
         * \brief 
         * 
         * \return None
         */
        void OnToggleButtonOpenClosePortToggled();
        /**
         * \brief 
         * 
         * \return
         */
        bool Timer();
        /**
         * \brief 
         * 
         * \return 
         */
        void OnToolButtonOpenClicked();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnToolButtonConfigClicked();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnToolButtonStatisticsClicked();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnToolButtonRunClicked();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnToolButtonAboutClicked();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnToggleButtonPlayBeaconToggled();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnToggleButtonPauseBeaconToggled();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnButtonStopBeaconClicked();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnButtonClearAllBeaconClicked();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnToggleButtonPlayTelemetryToggled();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnToggleButtonPauseTelemetryToggled();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnButtonStopTelemetryClicked();
        /**
         * \brief 
         * 
         * \return None
         */
        void OnButtonClearAllTelemetryClicked();
        /**
         * \brief 
         * 
         * \return None
         */
        void RaiseErrorMessage(const char* error_title, const char* error_text);
        /**
         * \brief 
         * 
         * \param beacon_receiver
         * 
         * \return None
         */
        void RunGNURadioReceiver(bool beacon_receiver=true);
    public:
        /**
         * \brief 
         * 
         * \return None
         */
        FSatPktAna();
        /**
         * \brief 
         * 
         * \param ref_builder
         * \param ui_file
         * 
         * \return None
         */
        FSatPktAna(Glib::RefPtr<Gtk::Builder> ref_builder, const char *ui_file);
        /**
         * \brief 
         * 
         * \return None
         */
        ~FSatPktAna();
        /**
         * \brief 
         * 
         * \param ref_builder
         * \param ui_file
         * 
         * \return Status code.
         */
        int BuildWidgets(Glib::RefPtr<Gtk::Builder> ref_builder, const char *ui_file);
        /**
         * \brief 
         * 
         * \param app
         * 
         * \return 
         */
        int Run(Glib::RefPtr<Gtk::Application> app);
        /**
         * \brief 
         * 
         * \param byte
         * 
         * \return 
         */
        std::vector<uint8_t> ProccessByte(uint8_t byte);
};

#endif // FSAT_PKT_ANA_H_

//! \} End of fsat_pkt_ana group
