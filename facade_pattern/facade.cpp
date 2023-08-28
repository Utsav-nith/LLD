#include <iostream>
#include <string>

class CarRental {
public:
    void rentCar(const std::string& carType, const std::string& start_date, const std::string& end_date) {
        std::cout << "Your car has been rented from " << start_date << " to " << end_date << std::endl;
    }
};

class FlightBooking {
public:
    void bookFlight(const std::string& source, const std::string& destination, const std::string& date) {
        std::cout << "Your flight has been booked from " << source << " to " << destination << " for " << date << std::endl;
    }
};

class HotelReservation {
public:
    void bookHotel(const std::string& start_date, const std::string& end_date, const std::string& hotelType) {
        std::cout << "Hotel has been booked from " << start_date << " to " << end_date << std::endl;
    }
};

class TravelBookingFacade {
    CarRental carRental;
    FlightBooking flightBooking;
    HotelReservation hotelReservation;

public:
    TravelBookingFacade() = default;

    void bookMyTrip(const std::string& destination, const std::string& start_date,
                    const std::string& end_date, const std::string& carType, const std::string& hotelName) {
        // Flight booking
        flightBooking.bookFlight("HOME", destination, start_date);

        // Rent a car
        carRental.rentCar(carType, start_date, end_date);

        // Book a hotel
        hotelReservation.bookHotel(start_date, end_date, hotelName);
    }
};

int main() {
    TravelBookingFacade travelBookingFacade;

    travelBookingFacade.bookMyTrip("Kashmir", "26/08/2023", "10/09/2023", "SUV", "Taj");

    return 0;
}