set(core_SRCS AbstractNode.cpp AbstractNode.h Bfs.cpp Bfs.h Cab.cpp Cab.h CarManufacturer.h
        Color.h Driver.cpp Driver.h FactoryCab.cpp FactoryCab.h Grid.h Grid.cpp LuxuryCab.cpp
        LuxuryCab.h MainFlow.cpp MainFlow.h MaritalStatus.h Matrix.cpp Matrix.h Node.cpp Node.h
        Passenger.cpp Passenger.h Point.cpp Point.h Searchable.cpp Searchable.h StandardCab.cpp
        StandardCab.h TaxiCenter.cpp TaxiCenter.h TripInformation.cpp TripInformation.h)

add_library(core ${core_SRCS})


