-- Keep a log of any SQL queries you execute as you solve the mystery.
--https://learnsql.com/cookbook/how-to-order-by-two-columns-in-sql/
--https://www.w3schools.com/sql/sql_join.asp
--https://www.w3schools.com/sql/func_sqlserver_cast.asp
--https://www.w3schools.com/sql/sql_ref_keywords.asp
--https://stackoverflow.com/questions/21425546/how-to-generate-a-range-of-numbers-between-two-numbers/33146869

-- check crime scene reports to get clues
SELECT * FROM "crime_scene_reports" WHERE "month" = '7' AND "day" = '28' AND "street" LIKE 'Chamberlin Street'
-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today
-- with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.


SELECT * FROM "interviews" WHERE "month" = '7' AND "day" = '28' AND "transcript" LIKE '%courthouse%'
--Ruth: Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
--      If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot
--      in that time frame.

--Eugene: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
--        I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

--Raymond: As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call,
--         I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked
--         the person on the other end of the phone to purchase the flight ticket.


--Find names of people who made ATM withdrawal at Fifer Street the day of the crime
SELECT people.name FROM bank_accounts
JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
JOIN people ON bank_accounts.person_id=people.id
WHERE atm_transactions.atm_location="Fifer Street" AND atm_transactions.month = '7'
AND atm_transactions.day = '28' AND atm_transactions.transaction_type = "withdraw";
--Output:
--name
--Ernest
--Russell
--Roy
--Bobby
--Elizabeth
--Danielle
--Madison
--Victoria


--People who left the parking lot on day of crime who also withdrew money from the Fifer Street ATM
SELECT people.name FROM courthouse_security_logs
JOIN people ON courthouse_security_logs.license_plate=people.license_plate
WHERE courthouse_security_logs.activity="exit"AND courthouse_security_logs.month='7' AND courthouse_security_logs.day='28'
AND courthouse_security_logs.hour='10' AND CAST(courthouse_security_logs.minute AS int) BETWEEN 15 AND 25
AND people.name IN(
--previous query
SELECT people.name FROM bank_accounts
JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
JOIN people ON bank_accounts.person_id=people.id
WHERE atm_transactions.atm_location="Fifer Street" AND atm_transactions.month = '7'
AND atm_transactions.day = '28' AND atm_transactions.transaction_type = "withdraw");
--Output:
--Ernest
--Danielle
--Elizabeth
--Russell
--Madison


--
--Find the first flight on the next day out of Fiftyville Regional Airport
SELECT airports.city FROM airports
WHERE airports.id IN(
SELECT flights.destination_airport_id FROM flights
JOIN airports ON flights.origin_airport_id=airports.id
WHERE flights.month='7' AND flights.day='29'AND airports.city="Fiftyville"
ORDER BY flights.hour, flights.minute
LIMIT 1);
--Output:
--London


--Find person who called for less than one minute who was also in the previous query
SELECT people.name FROM phone_calls
JOIN people ON phone_calls.caller=people.phone_number
WHERE phone_calls.month='7' AND phone_calls.day='28' AND CAST(phone_calls.duration AS int)<60
AND people.name IN(
--previous query
SELECT people.name FROM courthouse_security_logs
JOIN people ON courthouse_security_logs.license_plate=people.license_plate
WHERE courthouse_security_logs.activity="exit"AND courthouse_security_logs.month='7' AND courthouse_security_logs.day='28'
AND courthouse_security_logs.hour='10' AND CAST(courthouse_security_logs.minute AS int) BETWEEN 15 AND 25
AND people.name IN(
--previous query
SELECT people.name FROM bank_accounts
JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
JOIN people ON bank_accounts.person_id=people.id
WHERE atm_transactions.atm_location="Fifer Street" AND atm_transactions.month = '7'
AND atm_transactions.day = '28' AND atm_transactions.transaction_type = "withdraw"));
--Output:
--Ernest
--Madison
--Russell


--People in previous list that were on the flight to London from Fiftyville
SELECT people.name FROM passengers
JOIN people ON passengers.passport_number=people.passport_number
WHERE passengers.flight_id IN(
SELECT flights.id FROM flights
JOIN airports ON flights.origin_airport_id=airports.id
WHERE flights.month='7' AND flights.day='29'AND airports.city="Fiftyville"
ORDER BY flights.hour, flights.minute
LIMIT 1)
AND people.name IN(
-- previous query (phone calls)
SELECT people.name FROM phone_calls
JOIN people ON phone_calls.caller=people.phone_number
WHERE phone_calls.month='7' AND phone_calls.day='28' AND CAST(phone_calls.duration AS int)<60
AND people.name IN(
--previous query (courthouse_security_logs)
SELECT people.name FROM courthouse_security_logs
JOIN people ON courthouse_security_logs.license_plate=people.license_plate
WHERE courthouse_security_logs.activity="exit"AND courthouse_security_logs.month='7' AND courthouse_security_logs.day='28'
AND courthouse_security_logs.hour='10' AND CAST(courthouse_security_logs.minute AS int) BETWEEN 15 AND 25
AND people.name IN(
--previous query (atm_transactions)
SELECT people.name FROM bank_accounts
JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
JOIN people ON bank_accounts.person_id=people.id
WHERE atm_transactions.atm_location="Fifer Street" AND atm_transactions.month = '7'
AND atm_transactions.day = '28' AND atm_transactions.transaction_type = "withdraw")));
--Output:
--Ernest


--Find the person that Ernest called
SELECT people.name FROM phone_calls
JOIN people ON phone_calls.receiver=people.phone_number
WHERE phone_calls.month='7' AND phone_calls.day='28' AND CAST(phone_calls.duration AS int)<60
AND phone_calls.caller=(SELECT people.phone_number FROM people
WHERE people.name IN(
--This query will equal Ernest
SELECT people.name FROM passengers
JOIN people ON passengers.passport_number=people.passport_number
WHERE passengers.flight_id IN(
SELECT flights.id FROM flights
JOIN airports ON flights.origin_airport_id=airports.id
WHERE flights.month='7' AND flights.day='29'AND airports.city="Fiftyville"
ORDER BY flights.hour, flights.minute
LIMIT 1)
AND people.name IN(
-- previous query (phone calls)
SELECT people.name FROM phone_calls
JOIN people ON phone_calls.caller=people.phone_number
WHERE phone_calls.month='7' AND phone_calls.day='28' AND CAST(phone_calls.duration AS int)<60
AND people.name IN(
--previous query (courthouse_security_logs)
SELECT people.name FROM courthouse_security_logs
JOIN people ON courthouse_security_logs.license_plate=people.license_plate
WHERE courthouse_security_logs.activity="exit"AND courthouse_security_logs.month='7' AND courthouse_security_logs.day='28'
AND courthouse_security_logs.hour='10' AND CAST(courthouse_security_logs.minute AS int) BETWEEN 15 AND 25
AND people.name IN(
--previous query (atm_transactions)
SELECT people.name FROM bank_accounts
JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
JOIN people ON bank_accounts.person_id=people.id
WHERE atm_transactions.atm_location="Fifer Street" AND atm_transactions.month = '7'
AND atm_transactions.day = '28' AND atm_transactions.transaction_type = "withdraw")))
));
--Berthold