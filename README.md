# cansat-telemetry-gui
GUI built in Qt (C++) for CANSAT 2023
**Team KALPANA**
NSUT

![UI photo](home.jpeg "cangui")

## Telemetry
Upon power up, the CanSat shall collect the required telemetry at a one (1) Hz sample rate
and transmit the telemetry data to the ground station.
The ASCII format of the telemetry packets are described below. Each telemetry field is
delimited by a comma, and each telemetry packet is concluded by a single carriage return
character. No comma (‘,’) characters should be part of the data fields -- commas are
delimiters only.

## Telemetry Formats

The CanSat telemetry packet format to be transmitted at one (1) Hz is as follows:
TEAM_ID, MISSION_TIME, PACKET_COUNT, MODE, STATE, ALTITUDE,
HS_DEPLOYED, PC_DEPLOYED, MAST_RAISED, TEMPERATURE, VOLTAGE,
GPS_TIME, GPS_ALTITUDE, GPS_LATITUDE, GPS_LONGITUDE, GPS_SATS,
TILT_X, TILT_Y, CMD_ECHO [,,OPTIONAL_DATA]
The telemetry data fields are to be formatted as follows:
1. **TEAM_ID** is the assigned four digit team identification number. E.g., imaginary team
‘1000’.
2. **MISSION_TIME** is UTC time in format hh:mm:ss.ss, where hh is hours, mm is
minutes, and ss.ss is seconds (including hundredths of a second). E.g., ‘13:14:02.22’
indicates 1:14:02.22 PM.
3. **PACKET_COUNT** is the total count of transmitted packets since turn on, which is to be
reset to zero by command when the CanSat is installed in the rocket on the launch pad
at the beginning of the mission and maintained through processor reset.
4. **MODE** = ‘F’ for flight mode and ‘S’ for simulation mode.
5. **STATE** is the operating state of the software. (e.g., LAUNCH_WAIT, ASCENT,
ROCKET_SEPARATION, DESCENT, HS_RELEASE, LANDED, etc.). Teams may
define their own states. This should be a human readable description as the judges
will review it after the launch in the .csv files.
6. **ALTITUDE**** is the altitude in units of meters and must be relative to ground level at the
launch site. The resolution must be 0.1 meters.
7. **HS_DEPLOYED** = ‘P’ indicates the Probe with heat shield is deployed, ‘N’ otherwise.
8. **PC_DEPLOYED** = ‘C’ indicates the Probe parachute is deployed (at 200 m), ‘N’ otherwise.
9. **MAST_RAISED** = ‘M’ indicates the flag mast has been raised after landing, ‘N’ otherwise.
10. **TEMPERATURE** is the temperature in degrees Celsius with a resolution of 0.1
degrees.
11. **VOLTAGE** is the voltage of the CanSat power bus with a resolution of 0.1 volts.
12. **GPS_TIME** is the time from the GPS receiver. The time must be reported in UTC and
have a resolution of a second.
13. **GPS_ALTITUDE** is the altitude from the GPS receiver in meters above mean sea
level with a resolution of 0.1 meters.
14. **GPS_LATITUDE** is the latitude from the GPS receiver in decimal degrees with a
resolution of 0.0001 degrees North.
12
15. **GPS_LONGITUDE** is the longitude from the GPS receiver in decimal degrees with a
resolution of 0.0001 degrees West.
16. **GPS_SATS** is the number of GPS satellites being tracked by the GPS receiver. This
must be an integer.
17. **TILT_X, TILT_Y** are the angles of the CanSat X and Y axes in degrees, with a
resolution of 0.01 degrees, where zero degrees is defined as when the axes are
perpendicular to the Z axis which is defined as towards the center of gravity of the
Earth.
18. **CMD_ECHO** is the text of the last command received and processed by the CanSat.
For example, CXON or SP101325. See the command section for details of command
formats. Do not include commas characters.
19. **[,,OPTIONAL_DATA]** are zero or more additional fields the team considers important
following two commas, which indicates a blank field. This data must follow the same
format rules (including use of comma characters ‘,’) to facilitate review of the CSV files
by the judges after the mission.

