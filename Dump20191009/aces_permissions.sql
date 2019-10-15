-- MySQL dump 10.13  Distrib 5.7.27, for Linux (x86_64)
--
-- Host: localhost    Database: aces
-- ------------------------------------------------------
-- Server version	5.7.27-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `permissions`
--

DROP TABLE IF EXISTS `permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `permissions` (
  `idpermission_window` int(11) NOT NULL AUTO_INCREMENT,
  `start_time` time(4) DEFAULT NULL,
  `end_time` time(4) DEFAULT NULL,
  `Monday` tinyint(1) DEFAULT NULL,
  `Tuesday` tinyint(1) DEFAULT NULL,
  `Wednesday` tinyint(1) DEFAULT NULL,
  `Thursday` tinyint(1) DEFAULT NULL,
  `Friday` tinyint(1) DEFAULT NULL,
  `Saturday` tinyint(1) DEFAULT NULL,
  `sunday` tinyint(1) DEFAULT NULL,
  `permission_window_name` varchar(45) DEFAULT NULL,
  `can_mod_users` tinyint(1) DEFAULT NULL,
  `can_mod_system` tinyint(1) DEFAULT NULL,
  `can_access_door1` tinyint(1) DEFAULT NULL,
  `can_access_door2` tinyint(1) DEFAULT NULL,
  `can_access_door3` tinyint(1) DEFAULT NULL,
  `can_access_door4` tinyint(1) DEFAULT NULL,
  `can_access_door5` tinyint(1) DEFAULT NULL,
  `can_access_door6` tinyint(1) DEFAULT NULL,
  `access_item_button_enabled` tinyint(1) DEFAULT NULL,
  `access_group_button_enabled` tinyint(1) DEFAULT NULL,
  `Loggs_button_enabled` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`idpermission_window`),
  UNIQUE KEY `idtime_window_UNIQUE` (`idpermission_window`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `permissions`
--

LOCK TABLES `permissions` WRITE;
/*!40000 ALTER TABLE `permissions` DISABLE KEYS */;
INSERT INTO `permissions` VALUES (1,'08:00:00.0000','24:00:00.0000',1,1,1,1,1,1,1,'workday',1,1,1,1,1,1,1,1,1,1,1),(2,'08:00:00.0000','11:30:00.0000',1,1,1,1,1,1,1,'noone',0,0,1,0,0,0,0,0,0,0,0),(3,'08:00:00.0000','14:00:00.0000',1,1,1,1,1,0,0,'noone2',0,0,1,1,0,0,0,0,0,0,0),(4,'01:00:00.0000','24:00:00.0000',1,1,1,1,1,1,1,'Admin',1,1,1,1,0,0,0,0,1,1,1),(5,'01:00:00.0000','24:00:00.0000',1,1,1,1,1,0,0,'Door2',0,0,0,1,0,0,0,0,0,0,0);
/*!40000 ALTER TABLE `permissions` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-10-15 16:03:04
