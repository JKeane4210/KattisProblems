cmake_minimum_required(VERSION 3.17)
project(KattisProblems)

#set(CMAKE_CXX_STANDARD 14)

#add_executable(SingleSourceNegativeWeights singleSourceNegativeWeights.cpp)
#add_executable(WaifUntilDark WaifUntilDark.cpp)
#add_executable(Treehouse treehouses.cpp)
#add_executable(LostMap lostMap.cpp)
#add_executable(LostMap2 lostMap2.cpp)
#add_executable(01Sequences 01Sequences.cpp)
#add_executable(01Sequences2 01Sequences2.cpp)
#add_executable(ACMScoringContest ACMScoringContest.cpp)
#add_executable(A1Paper A1Paper.cpp)
#add_executable(LaptopSticker LaptopSticker.cpp)

#add_executable(10KindsOfPeople 10KindsOfPeople.cpp)
#add_executable(PearWiseVoting MSOE2021Summer/Week1/PearWiseVoting.cpp)
#add_executable(RomanHolidays MSOE2021Summer/Week1/RomanHolidays.cpp)
#add_executable(PizzaCutting MSOE2021Summer/Week1/PizzaCutting.cpp)
#add_executable(CarVet MSOE2021Summer/Week1/CarVet.cpp)
#add_executable(ToursDeSalesForce MSOE2021Summer/Week1/ToursDeSalesForce.cpp)
#add_executable(PunctiliousCruciverbalist MSOE2021Summer/Week1/PunctiliousCruciverbalist.cpp)
#add_executable(Difference MSOE2021Summer/Week1/Difference.cpp)
#add_executable(RandomProblem MSOE2021Summer/Week1/RandomProblem.cpp)
#add_executable(LandlineTelephoneNetwork MSOE2021Summer/Week2/LandlineTelephoneNetwork2.cpp)
#add_executable(LockedTreasure MSOE2021Summer/Week2/LockedTreasure.cpp)
#add_executable(RestaurantRatings MSOE2021Summer/Week2/RestaurantRatings.cpp)
#add_executable(FacilityLocations MSOE2021Summer/Week2/FacilityLocations.cpp)
#add_executable(Server MSOE2021Summer/Week2/Server.cpp)
#add_executable(ContinuedFraction MSOE2021Summer/Week2/ContinuedFraction.cpp)
#add_executable(PlaneTicketPricing MSOE2021Summer/Week2/PlaneTicketPricing.cpp)
#add_executable(RepeatedSubstrings MSOE2021Summer/Week2/RepeatedSubstrings.cpp)
#add_executable(AquariumTank MSOE2021Summer/Week2/AquariumTank.cpp)
#add_executable(FizzBuzz MSOE2021Summer/Week3/FizzBuzz.cpp)
#add_executable(FlowShop MSOE2021Summer/Week3/FlowShop3.cpp)
#add_executable(Election MSOE2021Summer/Week3/Election.cpp)
#add_executable(PasswordHacking MSOE2021Summer/Week3/PasswordHacking.cpp)
#add_executable(BumperToBumperTraffic MSOE2021Summer/Week3/BumperToBumperTraffic.cpp)
#add_executable(DeliveringGoods MSOE2021Summer/Week3/DeliveringGoods.cpp)
#add_executable(FroshWeek MSOE2021Summer/Week4/FroshWeek.cpp)
#add_executable(HeartRate MSOE2021Summer/Week4/HeartRate.cpp)
#add_executable(HissingMicrophone MSOE2021Summer/Week4/HissingMicrophone.cpp)
#add_executable(PalindromicPassword MSOE2021Summer/Week4/PalindromicPassword.cpp)
#add_executable(PolylineSimplification MSOE2021Summer/Week4/PolylineSimplification.cpp)
#add_executable(FlowFree MSOE2021Summer/Week4/FlowFree.cpp)
#add_executable(DecisionsDecisions MSOE2021Summer/Week4/DecisionsDecisions.cpp)
#add_executable(MultiplicationGame MSOE2021Summer/Week4/MultiplicationGame.cpp)
#add_executable(Initials MSOE2021Summer/Week4/Initials.cpp)
#add_executable(OpenPitMining MSOE2021Summer/Week4/OpenPitMining3.cpp)
#add_executable(BioTrip MSOE2021Summer/Week5/BioTrip2.cpp)
#add_executable(MusicalChairs MSOE2021Summer/Week5/MusicalChairs.cpp)
#add_executable(Retribution MSOE2021Summer/Week5/Retribution.cpp)
#add_executable(TaxedEditor MSOE2021Summer/Week5/TaxedEditor.cpp)
#add_executable(JustPassingThrough MSOE2021Summer/Week5/JustPassingThrough.cpp)
#add_executable(WhatsOnTheGrille MSOE2021Summer/Week6/WhatsOnTheGrille.cpp)
#add_executable(Rings MSOE2021Summer/Week6/Rings.cpp)
#add_executable(SquawkVirus MSOE2021Summer/Week6/SquawkVirus.cpp)
#add_executable(KenKenYouDoIt MSOE2021Summer/Week6/KenKenYouDoIt.cpp)
#add_executable(TransportationDelegation MSOE2021Summer/Week6/TransportationDelegation.cpp)
#add_executable(TrayBien MSOE2021Summer/Week6/TrayBien.cpp)
#add_executable(DeleteThis MSOE2021Summer/Week6/DeleteThis.cpp)
#add_executable(4Thought MSOE2021Summer/Week7/4Thought.cpp)
#add_executable(Oddities MSOE2021Summer/Week7/Oddities.cpp)
#add_executable(IslandBuses MSOE2021Summer/Week7/IslandBuses.cpp)
#add_executable(EvenUpSolitaire MSOE2021Summer/Week7/EvenUpSolitaire.cpp)
#add_executable(GoldbachsConjecture MSOE2021Summer/Week7/GoldbachsConjecture.cpp)
#add_executable(ErraticAnts MSOE2021Summer/Week7/ErraticAnts.cpp)
#add_executable(TrapezoidWalkway MSOE2021Summer/Week7/TrapezoidWalkway.cpp)
#add_executable(TernarianWeights MSOE2021Summer/Week7/TernarianWeights3.cpp)
#add_executable(PlottingPolynomials MSOE2021Summer/Week7/PlottingPolynomials.cpp)
#add_executable(BiggestSlice MSOE2021Summer/Week7/BiggestSlice.cpp)
#add_executable(ShotCube MSOE2021Summer/Week7/ShotCube.cpp)
#add_executable(PrimalRepresentation MSOE2021Summer/NAPCPracticeContest_Jul10/PrimalRepresentation.cpp)
#add_executable(BabelFisch MSOE2021Summer/NAPCPracticeContest_Jul10/BabelFisch.cpp)
#add_executable(EatingOut MSOE2021Summer/NAPCPracticeContest_Jul10/EatingOut.cpp)
#add_executable(DisastrousDoubling MSOE2021Summer/NAPCPracticeContest_Jul10/DisastrousDoubling.cpp)
#add_executable(FlightPlans MSOE2021Summer/NAPCPracticeContest_Jul10/FlightPlans.cpp)
#add_executable(BrickWall MSOE2021Summer/NAPCPracticeContest_Jul10/BrickWall.cpp)
#add_executable(Tourists MSOE2021Summer/Week8/Tourists2.cpp)
#add_executable(TimeIsMoney MSOE2021Summer/NAPCPracticeContest_Jul17/TimeIsMoney.cpp)
#add_executable(JugglingTroupe MSOE2021Summer/NAPCPracticeContest_Jul17/JugglingTroupe.cpp)
#add_executable(Mathemagicians MSOE2021Summer/NAPCPracticeContest_Jul17/Mathemagicians.cpp)
#add_executable(FlashingFluorescents MSOE2021Summer/Week9/FlashingFluorescents.cpp)
#add_executable(MissingGnomes MSOE2021Summer/Week9/MissingGnomes2.cpp)
#add_executable(ProbeDroids MSOE2021Summer/Week9/ProbeDroids.cpp)
#add_executable(ZoningHouses MSOE2021Summer/Week9/ZoningHouses.cpp)
#add_executable(MaximalSequences MSOE2021Summer/NAPCPracticeContest_Jul25/MaximalSequences2.cpp)
#add_executable(Totem MSOE2021Summer/NAPCPracticeContest_Jul25/Totem.cpp)
#add_executable(DamsInDistress MSOE2021Summer/Week10/DamsInDistress.cpp)
#add_executable(ArrayOfDiscord MSOE2021Summer/Week10/ArrayOfDiscord.cpp)
#add_executable(CoinStacks MSOE2021Summer/Week10/CoinStacks.cpp)
#add_executable(InfectionEstimation MSOE2021Summer/Week10/InfectionEstimation.cpp)
#add_executable(Candyland MSOE2021Summer/NAPCPracticeContest_Jul31/Candyland.cpp)
#add_executable(EenyMeeny MSOE2021Summer/Week11/EenyMeeny.cpp)
#add_executable(AlphabetAnimals MSOE2021Summer/Week11/AlphabetAnimals.cpp)
#add_executable(L2 MSOE2021Summer/NSAChallenge/L2.cpp)

#add_executable(MatrixInverse MSOE2020/MatrixInverse.cpp)
#add_executable(ClassyProblem MSOE2021Fall/RMRC2015/ClassyProblem.cpp)
#add_executable(ScalingRecipes MSOE2021Fall/RMRC2015/ScalingRecipes.cpp)
#add_executable(PopularVote MSOE2021Fall/RMRC2015/PopularVote.cpp)
#add_executable(MatrixKeypad MSOE2021Fall/RMRC2015/MatrixKeypad.cpp)
#add_executable(TheMagical3 MSOE2021Fall/RMRC2015/TheMagical3.cpp)

#add_executable(BadPacking MSOE2021Fall/Week1/BadPacking.cpp)
#add_executable(DominatingDUos MSOE2021Fall/Week1/DominatingDuos.cpp)
#add_executable(MagicTrick MSOE2021Fall/Week1/MagicTrick.cpp)
#add_executable(MissingNumber MSOE2021Fall/Week1/MissingNumber.cpp)
#add_executable(NoThanks MSOE2021Fall/Week1/NoThanks.cpp)
#add_executable(RatingProblems MSOE2021Fall/Week1/RatingProblems.cpp)
#add_executable(SmoothieStand MSOE2021Fall/Week1/SmoothieStand.cpp)
#add_executable(TriangularCollection MSOE2021Fall/Week1/TriangularCollection.cpp)
add_executable(UnreadMessages MSOE2021Fall/Week1/UnreadMessages.cpp)
#add_executable(Stopwatch MSOE2021Fall/Week5/Stopwatch.cpp)
#add_executable(IntegerDivision MSOE2021Fall/Week6/IntegerDivision.cpp)
#add_executable(FantasyDraft MSOE2021Fall/Week6/FantasyDraft.cpp)
#add_executable(LostLineup MSOE2021Fall/Week6/LostLineup.cpp)
#add_executable(PieceOfCake MSOE2021Fall/Week6/PieceOfCake.cpp)
#add_executable(FoldingACube MSOE2021Fall/Week6/FoldingACube.cpp)
#add_executable(TheBiggestTriangle MSOE2021Fall/Week6/TheBiggestTriangle.cpp)
#add_executable(Hogwarts MSOE2021Fall/Week6/Hogwarts.cpp)
#add_executable(TiredTerry MSOE2021Fall/Week6/TiredTerry.cpp)
#add_executable(QualityAdjustedLifeYear MSOE2021Fall/Week7/QualityAdjustedLifeYear.cpp)
#add_executable(HIndex MSOE2021Fall/Week7/HIndex.cpp)
#add_executable(NeighborhoodWatch MSOE2021Fall/Week7/NeighborhoodWatch.cpp)
#add_executable(SmallSchedule MSOE2021Fall/Week7/SmallSchedule.cpp)
#add_executable(QuiteAProblem MSOE2021Fall/Week8/QuiteAProblem.cpp)

# --- NAQ 2019 ---
#add_executable(CircuitMath MSOE2022Winter/NAQ2019/CircuitMath.cpp)
#add_executable(MissingNumbers MSOE2022Winter/NAQ2019/MissingNumbers.cpp)
#add_executable(Gerrymandering MSOE2022Winter/NAQ2019/Gerrymandering.cpp)
#add_executable(DiagonalCut MSOE2022Winter/NAQ2019/DiagonalCut.cpp)
#add_executable(Zipline MSOE2022Winter/NAQ2019/Zipline.cpp)
#add_executable(StopCounting MSOE2022Winter/NAQ2019/StopCounting.cpp)
#add_executable(SummerTrip MSOE2022Winter/NAQ2019/SummerTrip.cpp)
#add_executable(ResearchProductivityIndex MSOE2022Winter/NAQ2019/ResearchProductivityIndex.cpp)

## --- NAQ 2021 ---
#add_executable(E_NAQ2021 MSOE2022Winter/NAQ2021/E_NAQ2021.cpp)
#add_executable(F_NAQ2021 MSOE2022Winter/NAQ2021/F_NAQ2021.cpp)
#add_executable(G_NAQ2021 MSOE2022Winter/NAQ2021/G_NAQ2021.cpp)
#add_executable(H_NAQ2021 MSOE2022Winter/NAQ2021/H_NAQ2021.cpp)
#add_executable(C_NAQ2021 MSOE2022Winter/NAQ2021/C_NAQ2021.cpp)
#add_executable(C2_NAQ2021 MSOE2022Winter/NAQ2021/C2_NAQ2021.cpp)
#add_executable(L_NAQ2021 MSOE2022Winter/NAQ2021/L_NAQ2021.cpp)
#
## --- Kotlinaughts Practice 1 ---
#add_executable(Practice1_D MSOE2022Winter/Practice1/Practice1_D.cpp)
#add_executable(Practice1_C MSOE2022Winter/Practice1/Practice1_C.cpp)
#add_executable(Practice1_B MSOE2022Winter/Practice1/Practice1_B.cpp)
#add_executable(Practice1_E MSOE2022Winter/Practice1/Practice1_E.cpp)
#add_executable(Practice1_F MSOE2022Winter/Practice1/Practice1_F.cpp)
#add_executable(Practice1_K MSOE2022Winter/Practice1/Practice1_K.cpp)
#
## --- Kotlinaughts Practice 2 ---
#add_executable(Practice2_C MSOE2022Winter/Practice2/Practice2_C.cpp)
#add_executable(Practice2_A MSOE2022Winter/Practice2/Practice2_A.cpp)
#add_executable(Practice2_B MSOE2022Winter/Practice2/Practice2_B.cpp)
#add_executable(Practice2_H MSOE2022Winter/Practice2/Practice2_H.cpp)
#add_executable(Practice2_G MSOE2022Winter/Practice2/Practice2_G.cpp)

## --- NCPC 2021 ---
#add_executable(NCPC2021_A MSOE2022Winter/NCPC_2021/NCPC2021_A.cpp)
#add_executable(NCPC2021_K MSOE2022Winter/NCPC_2021/NCPC2021_K.cpp)
#add_executable(NCPC2021_L MSOE2022Winter/NCPC_2021/NCPC2021_L.cpp)
#add_executable(NCPC2021_J MSOE2022Winter/NCPC_2021/NCPC2021_J.cpp)
#add_executable(NCPC2021_G MSOE2022Winter/NCPC_2021/NCPC2021_G.cpp)
#add_executable(NCPC2021_F MSOE2022Winter/NCPC_2021/NCPC2021_F.cpp)
#add_executable(NCPC2021_D MSOE2022Winter/NCPC_2021/NCPC2021_D.cpp)
#add_executable(NCPC2021_H MSOE2022Winter/NCPC_2021/NCPC2021_H.cpp)
#add_executable(NCPC2021_C MSOE2022Winter/NCPC_2021/NCPC2021_C2.cpp)
#add_executable(_topological_sort MSOE2022Winter/NCPC_2021/_topological_sort.cpp)
#
## --- NCPC 2018 ---
#add_executable(NCPC2018_B MSOE2022Winter/NCPC_2018/NCPC2018_B.cpp)
#add_executable(NCPC2018_C MSOE2022Winter/NCPC_2018/NCPC2018_C.cpp)
#add_executable(NCPC2018_H MSOE2022Winter/NCPC_2018/NCPC2018_H.cpp)
#add_executable(NCPC2018_I MSOE2022Winter/NCPC_2018/NCPC2018_I.cpp)
#
## --- Kotlinaughts Practice 3 ---
#add_executable(Practice3_G MSOE2022Winter/Practice3/Practice3_G.cpp)
#add_executable(Practice3_G2 MSOE2022Winter/Practice3/Practice3_G3.cpp)
#
## --- BAPC 2021 ---
#add_executable(BAPC2021_A MSOE2022Winter/BAPC2021/BAPC2021_A.cpp)
#add_executable(BAPC2021_I MSOE2022Winter/BAPC2021/BAPC2021_I.cpp)
#add_executable(BAPC2021_F MSOE2022Winter/BAPC2021/BAPC2021_F.cpp)
#add_executable(BAPC2021_C MSOE2022Winter/BAPC2021/BAPC2021_C.cpp)
#add_executable(BAPC2021_B MSOE2022Winter/BAPC2021/BAPC2021_B.cpp)

# --- NCNA 2021 ---
#add_executable(NCNA_2021_I MSOE2022Winter/NCNA_2021/NCNA_2021_I.cpp)
#add_executable(NCNA_2021_G MSOE2022Winter/NCNA_2021/NCNA_2021_G.cpp)
#add_executable(NCNA_2021_L MSOE2022Winter/NCNA_2021/NCNA_2021_L.cpp)
#add_executable(NCNA_2021_D MSOE2022Winter/NCNA_2021/NCNA_2021_D.cpp)
#add_executable(NCNA_2021_E MSOE2022Winter/NCNA_2021/NCNA_2021_E.cpp)
#add_executable(NCNA_2021_C MSOE2022Winter/NCNA_2021/NCNA_2021_C.cpp)
#add_executable(NCNA_2021_J MSOE2022Winter/NCNA_2021/NCNA_2021_J.cpp)
#add_executable(NCNA_2021_F MSOE2022Winter/NCNA_2021/NCNA_2021_F.cpp)
#add_executable(NCNA_2021_M MSOE2022Winter/NCNA_2021/NCNA_2021_M.cpp)
#add_executable(NCNA_2021_A MSOE2022Winter/NCNA_2021/NCNA_2021_A.cpp)
#add_executable(NCNA_2021_H MSOE2022Winter/NCNA_2021/NCNA_2021_H.cpp)
#add_executable(NCNA_2021_B MSOE2022Winter/NCNA_2021/NCNA_2021_B.cpp)
#add_executable(NCNA_2021_BSlow MSOE2022Winter/NCNA_2021/NCNA_2021_BSlow.cpp)
#add_executable(NCNA_2021_K MSOE2022Winter/NCNA_2021/NCNA_2021_K.cpp)
#
## --- BAPC 2013 ---
#add_executable(BAPC2013_A MSOE2022Winter/BAPC2013/BAPC2013_A.cpp)
#add_executable(BAPC2013_I MSOE2022Winter/BAPC2013/BAPC2013_I.cpp)
#add_executable(BAPC2013_F MSOE2022Winter/BAPC2013/BAPC2013_F.cpp)
#add_executable(BAPC2013_C MSOE2022Winter/BAPC2013/BAPC2013_C.cpp)
#add_executable(BAPC2013_D MSOE2022Winter/BAPC2013/BAPC2013_D.cpp)
#add_executable(BAPC2013_B MSOE2022Winter/BAPC2013/BAPC2013_B.cpp)
#
#
#add_executable(NWERC_2020_C MSOE2022Spring/NWERC_2020/C.cpp)
#add_executable(NWERC_2020_K MSOE2022Spring/NWERC_2020/K.cpp)
#add_executable(NWERC_2020_H MSOE2022Spring/NWERC_2020/H.cpp)
#add_executable(NWERC_2020_D MSOE2022Spring/NWERC_2020/D.cpp)
#add_executable(NWERC_2020_E MSOE2022Spring/NWERC_2020/E.cpp)
#add_executable(NWERC_2020_I MSOE2022Spring/NWERC_2020/I.cpp)
#
#add_executable(MSOE_DP_A MSOE2022Spring/MSOE_CP_DP/A.cpp)
#add_executable(MSOE_DP_B MSOE2022Spring/MSOE_CP_DP/B.cpp)
#add_executable(MSOE_DP_C MSOE2022Spring/MSOE_CP_DP/C.cpp)
#add_executable(MSOE_DP_D MSOE2022Spring/MSOE_CP_DP/D.cpp)
#
#add_executable(DisjointMinTable MSOE2022Spring/MCPC21/DisjointMinTable.cpp)
#add_executable(DoublePassword MSOE2022Spring/MCPC21/DoublePassword.cpp)
#add_executable(WhoGoesThere MSOE2022Spring/MCPC21/WhoGoesThere.cpp)
#
#add_executable(MiniBattleship MSOE2022Spring/NAC_2020/MiniBattleship.cpp)
#add_executable(Hopscotch50 MSOE2022Spring/NAC_2020/Hopscotch50.cpp)
#add_executable(LetterWheels MSOE2022Spring/NAC_2020/LetterWheels.cpp)
#add_executable(PunchCard MSOE2022Spring/CodeJam/Qualifying/PunchCard.cpp)
#add_executable(3DPrinting MSOE2022Spring/CodeJam/Qualifying/3DPrinting.cpp)
#add_executable(dn MSOE2022Spring/CodeJam/Qualifying/dn.cpp)

#add_executable(DoubleOrOneThing MSOE2022Spring/CodeJam/1A/DoubleOrOneThing.cpp)
#add_executable(EqualSum MSOE2022Spring/CodeJam/1A/EqualSum.cpp)
#add_executable(WeightLifting MSOE2022Spring/CodeJam/1A/WeightLifting.cpp)
#
#add_executable(PancakeDeque MSOE2022Spring/CodeJam/1B/PancakeDeque.cpp)
#
#add_executable(ConquestCampaign MSOE2022Spring/NAC2022_Practice3/ConquestCampaign.cpp)
#add_executable(HydraHeads MSOE2022Spring/NAC2022_Practice3/HydraHeads.cpp)
#
#add_executable(HowManySquares MSOE2022Spring/NAC2022_Practice5_Plane/HowManySquares.cpp)
##add_executable(HowManySquaresTLE MSOE2022Spring/NAC2022_Practice5_Plane/HowManySquaresTLE.cpp)
#
#add_executable(SpiralingIntoControl MSOE2022Spring/CodeJam/2/SpiralingIntoControl.cpp)
#add_executable(PixelatedCircle MSOE2022Spring/CodeJam/2/PixelatedCircle.cpp)
#
#add_executable(DiceGame MSOE2022Spring/NAC2022_Practice5/DiceGame.cpp)
#add_executable(OpeningCeremony MSOE2022Spring/NAC2022_Practice5/OpeningCeremony.cpp)
#add_executable(TrainPassengers MSOE2022Spring/NAC2022_Practice5/TrainPassengers.cpp)
#add_executable(ClockPictures MSOE2022Spring/NAC2022_Practice5/ClockPictures.cpp MSOE2022Spring/NAPC2022/Day1/Pinfall.cpp MSOE2022Spring/NAPC2022/Day2/CantStopPlaying.cpp)
#add_executable(Outing MSOE2022Spring/NAC2022_Practice5/Outing.cpp)
##add_executable(HowManySquares MSOE2022Spring/NAC2022_Practice5/HowManySquares.cpp)
#
#add_executable(TBOB MSOE2022Spring/Other/ThreeBlueOneBrownVid.cpp)
#add_executable(Pinfall MSOE2022Spring/NAPC2022/Day1/Pinfall.cpp)
#
#add_executable(CantStopPlaying MSOE2022Spring/NAPC2022/Day2/CantStopPlaying.cpp)
#add_executable(AnimalClass MSOE2022Spring/NAPC2022/Day2/AnimalClassification.cpp)
#
## ------------------------------ NAC 2022 ------------------------------
#
#add_executable(WordLadder MSOE2022Spring/NAC22/WordLadder.cpp)
#add_executable(TicTacToeCounting MSOE2022Spring/NAC22/TicTacToeCounting.cpp)
#add_executable(ContactTracing MSOE2022Spring/NAC22/ContactTracing.cpp)
#add_executable(RaftingTrip MSOE2022Spring/NAC22/RaftingTrip.cpp)
#add_executable(Reset MSOE2022Spring/NAC22/Reset.cpp)

#add_executable(EnergyDrinks MSOE2022Spring/NAPC2022/Lockout/EnergyDrinks.cpp)
#add_executable(CurrencySys MSOE2022Spring/NAPC2022/Lockout/CurrencySys.cpp)

#add_executable(Accounting MSOE2022Summer/RandomProblems/Accounting.cpp)
#add_executable(EightQueens MSOE2022Summer/RandomProblems/EightQueens.cpp)
#add_executable(zipflaw MSOE2022Fall/W2/zipflaw.cpp)
#add_executable(cuttingcorners MSOE2022Fall/W2/cuttingcorners.cpp)
#add_executable(savingtheuniverse MSOE2022Fall/W2/savingtheuniverse.cpp)
#add_executable(numbersonatree MSOE2022Fall/W3/numbersonatree.cpp)
#add_executable(chewbacca MSOE2022Fall/W3/chewbacca.cpp)
#add_executable(marblesonatree MSOE2022Fall/W3/marblesonatree.cpp)
#add_executable(grid MSOE2022Fall/W4/grid.cpp)
#add_executable(wheresmyinternet MSOE2022Fall/W4/wheresmyinternet.cpp)
#add_executable(weakvertices MSOE2022Fall/W4/weakvertices.cpp)
#add_executable(dungeonmaster MSOE2022Fall/W4/dungeonmaster.cpp)
#
#
#add_executable(8BitTollRoad MSOE2022Fall/BuckeyeProgrammingComp/EightBitTollRoad.cpp)
#
#add_executable(A MSOE2022Fall/Codeforces833/A.cpp)
#add_executable(B MSOE2022Fall/Codeforces833/B.cpp)
#add_executable(C MSOE2022Fall/Codeforces833/C.cpp)
#add_executable(D MSOE2022Fall/CodeTON3/D.cpp)
#
#add_executable(EvenUpSolitaire MSOE2023Winter/EvenUpSolitaire.cpp)
#add_executable(01Seq MSOE2023Winter/01Sequences.cpp)

#add_executable(BeastBullies MSOE2023Winter/NAQ/BeastBullies.cpp)
#add_executable(SpideyDistance MSOE2023Winter/NAQ/SpideyDistance.cpp)
#add_executable(ClassFieldTrip MSOE2023Winter/NAQ/ClassFieldTrip.cpp)
#add_executable(GhostLeg MSOE2023Winter/NAQ/GhostLeg.cpp)
#add_executable(TollRoads MSOE2023Winter/NAQ/TollRoads.cpp)
#add_executable(PlatformPlacing MSOE2023Winter/NAQ/PlatformPlacing.cpp)
#add_executable(MazeMan MSOE2023Winter/NAQ/MazeMan.cpp)
#add_executable(MovieNight MSOE2023Winter/NAQ/MovieNight.cpp)
#add_executable(RoomEvacuation MSOE2023Winter/NAQ/RoomEvacuation.cpp)
#add_executable(BirthdayGift MSOE2023Winter/NAQ/BirthdayGift.cpp)
#add_executable(Bribe MSOE2023Winter/Bribe.cpp)
#add_executable(LostLineup MSOE2023Winter/LostLineup.cpp)
#add_executable(IntegerDivision MSOE2023Winter/IntegerDivision.cpp)
#add_executable(NoThanks MSOE2023Winter/NoThanks.cpp)
#add_executable(PieceOfCake MSOE2023Winter/PieceOfCake.cpp)
#add_executable(ChainReactions MSOE2023Winter/ChainReactions.cpp)
#
#
#add_executable(LastGuess MSOE2023Spring/NWERC22/LastGuess.cpp)
#add_executable(InterviewQuestion MSOE2023Spring/NWERC22/InterviewQuestion.cpp)
#add_executable(NatureReserve MSOE2023Spring/NatureReserve.cpp)
#add_executable(JusticeServed MSOE2023Spring/NWERC22/JusticeServed.cpp)
#add_executable(PlayingWGeometry MSOE2023Spring/SWERC2014/PlayingWGeometry.cpp)
#add_executable(FloweryTrails MSOE2023Spring/SWERC2014/FloweryTrails.cpp)
#add_executable(BookClub MSOE2023Spring/SWERC2014/BookClub.cpp)
#add_executable(SlideCount MSOE2023Spring/SlideCount.cpp)
#add_executable(Beacons MSOE2023Spring/Beacons.cpp)
#add_executable(RoyAndCoinBoxes MSOE2023Spring/RoyAndCoinBoxes.cpp)
#add_executable(CribbageOnSteroids MSOE2023Spring/Plane/CribbageOnSteroids.cpp)
#add_executable(AmazingPuzzle MSOE2023Spring/Plane/AmazingPuzzle.cpp)
#add_executable(Uglinees MSOE2022Spring/NAPC2022/Lockout/Uglinesss.cpp)
#add_executable(Books MSOE2022Spring/NAPC2022/Lockout/A.cpp)
#add_executable(Grid MSOE2022Spring/NAPC2022/Lockout/C.cpp)
#add_executable(Tens MSOE2022Spring/NAPC2022/Lockout/D.cpp)
#include_directories(/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++)
#include_directories(/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1)
add_executable(AbstractPaint MSOE2023Spring/NAPC/Day1/AbstractPainting.cpp)
add_executable(OnceUponATime MSOE2023Spring/NAPC/Day1/OnceUponATime.cpp)
add_executable(GameDesign MSOE2023Spring/NAPC/Day1/GameDesign.cpp)
add_executable(InkBlots MSOE2023Spring/NAPC/Day1/InkBlots.cpp)