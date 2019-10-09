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
-- Table structure for table `event_log`
--

DROP TABLE IF EXISTS `event_log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `event_log` (
  `idevent_log` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `event_user_id` int(11) DEFAULT NULL,
  `event_date` date DEFAULT NULL,
  `event_time` varchar(45) DEFAULT NULL,
  `event_code` int(11) DEFAULT NULL,
  `event_detail` varchar(45) DEFAULT NULL,
  UNIQUE KEY `idevent_log_UNIQUE` (`idevent_log`)
) ENGINE=InnoDB AUTO_INCREMENT=363 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `event_log`
--

LOCK TABLES `event_log` WRITE;
/*!40000 ALTER TABLE `event_log` DISABLE KEYS */;
INSERT INTO `event_log` VALUES (285,NULL,'2019-10-09','08:28:25',1,NULL),(286,NULL,'2019-10-09','08:28:35',1,NULL),(287,NULL,'2019-10-09','08:28:39',1,NULL),(288,NULL,'2019-10-09','08:28:44',911,NULL),(289,NULL,'2019-10-09','08:28:48',911,NULL),(290,5,'2019-10-09','08:28:54',2,'Mark Meadows'),(291,5,'2019-10-09','08:28:59',4,'Mark Meadows'),(292,5,'2019-10-09','08:29:04',4,'Mark Meadows'),(293,5,'2019-10-09','08:29:19',3,'Mark Meadows'),(294,NULL,'2019-10-09','08:29:22',911,NULL),(295,NULL,'2019-10-09','08:35:29',1,NULL),(296,NULL,'2019-10-09','08:35:41',1,NULL),(297,5,'2019-10-09','08:35:47',2,'Mark Meadows'),(298,5,'2019-10-09','08:35:50',21,'Mark Meadows'),(299,5,'2019-10-09','08:35:57',3,'Mark Meadows'),(300,NULL,'2019-10-09','08:47:42',1,NULL),(301,5,'2019-10-09','08:47:47',2,'Mark Meadows'),(302,5,'2019-10-09','08:47:49',21,'Mark Meadows'),(303,5,'2019-10-09','08:48:26',3,'Mark Meadows'),(304,NULL,'2019-10-09','08:49:00',1,NULL),(305,5,'2019-10-09','08:49:04',2,'Mark Meadows'),(306,5,'2019-10-09','08:49:05',21,'Mark Meadows'),(307,5,'2019-10-09','08:49:51',3,'Mark Meadows'),(308,11,'2019-10-09','08:49:58',2,'Brian Meadows'),(309,11,'2019-10-09','08:50:00',4,'Brian Meadows'),(310,11,'2019-10-09','08:50:13',3,'Brian Meadows'),(311,4,'2019-10-09','08:50:21',2,'Steve Meadows'),(312,4,'2019-10-09','08:50:29',3,'Steve Meadows'),(313,5,'2019-10-09','08:50:36',2,'Mark Meadows'),(314,5,'2019-10-09','08:50:46',3,'Mark Meadows'),(315,4,'2019-10-09','08:50:54',2,'Steve Meadows'),(316,4,'2019-10-09','08:51:37',3,'Steve Meadows'),(317,5,'2019-10-09','08:52:21',2,'Mark Meadows'),(318,5,'2019-10-09','08:52:23',21,'Mark Meadows'),(319,5,'2019-10-09','08:52:51',17,'Mark Meadows'),(320,5,'2019-10-09','08:52:58',18,'Mark Meadows'),(321,5,'2019-10-09','08:53:28',3,'Mark Meadows'),(322,NULL,'2019-10-09','08:54:29',1,NULL),(323,NULL,'2019-10-09','08:54:34',1,NULL),(324,5,'2019-10-09','08:54:48',2,'Mark Meadows'),(325,5,'2019-10-09','08:54:55',3,'Mark Meadows'),(326,5,'2019-10-09','08:55:00',2,'Mark Meadows'),(327,5,'2019-10-09','08:55:26',17,'Mark Meadows'),(328,5,'2019-10-09','08:55:29',18,'Mark Meadows'),(329,5,'2019-10-09','08:55:53',3,'Mark Meadows'),(330,NULL,'2019-10-09','08:56:37',1,NULL),(331,NULL,'2019-10-09','08:56:41',1,NULL),(332,5,'2019-10-09','09:14:42',2,'Mark Meadows'),(333,5,'2019-10-09','09:14:44',17,'Mark Meadows'),(334,5,'2019-10-09','09:14:46',18,'Mark Meadows'),(335,5,'2019-10-09','09:14:50',3,'Mark Meadows'),(336,NULL,'2019-10-09','09:18:37',1,NULL),(337,5,'2019-10-09','09:25:51',2,'Mark Meadows'),(338,5,'2019-10-09','09:25:54',3,'Mark Meadows'),(339,NULL,'2019-10-09','09:26:03',911,NULL),(340,5,'2019-10-09','09:29:03',2,'Mark Meadows'),(341,5,'2019-10-09','09:29:09',4,'Mark Meadows'),(342,5,'2019-10-09','09:29:25',3,'Mark Meadows'),(343,11,'2019-10-09','09:29:36',2,'Brian Meadows'),(344,11,'2019-10-09','09:29:39',4,'Brian Meadows'),(345,11,'2019-10-09','09:29:41',3,'Brian Meadows'),(346,4,'2019-10-09','09:30:05',2,'Steve Meadows'),(347,4,'2019-10-09','09:30:10',3,'Steve Meadows'),(348,NULL,'2019-10-09','09:31:04',911,NULL),(349,NULL,'2019-10-09','09:31:07',911,NULL),(350,NULL,'2019-10-09','09:40:40',1,NULL),(351,NULL,'2019-10-09','09:40:47',911,NULL),(352,NULL,'2019-10-09','10:34:54',911,NULL),(353,NULL,'2019-10-09','10:35:00',911,NULL),(354,NULL,'2019-10-09','10:58:26',1,NULL),(355,5,'2019-10-09','10:58:33',2,'Mark Meadows'),(356,5,'2019-10-09','10:58:35',3,'Mark Meadows'),(357,NULL,'2019-10-09','10:58:37',911,NULL),(358,NULL,'2019-10-09','10:58:40',911,NULL),(359,NULL,'2019-10-09','10:58:42',911,NULL),(360,5,'2019-10-09','10:58:49',2,'Mark Meadows'),(361,5,'2019-10-09','10:58:50',4,'Mark Meadows'),(362,5,'2019-10-09','10:59:05',3,'Mark Meadows');
/*!40000 ALTER TABLE `event_log` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-10-09 12:21:44
