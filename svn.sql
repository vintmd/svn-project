-- MySQL dump 10.13  Distrib 5.5.53, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: svn
-- ------------------------------------------------------
-- Server version	5.5.53-0+deb8u1

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
-- Table structure for table `file_list`
--

DROP TABLE IF EXISTS `file_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `file_list` (
  `file_id` int(10) unsigned DEFAULT NULL,
  `file_name` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `file_list`
--

LOCK TABLES `file_list` WRITE;
/*!40000 ALTER TABLE `file_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `file_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `group_list`
--

DROP TABLE IF EXISTS `group_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `group_list` (
  `group_id` int(10) unsigned DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `count` int(10) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `group_list`
--

LOCK TABLES `group_list` WRITE;
/*!40000 ALTER TABLE `group_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `group_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `operate_type_list`
--

DROP TABLE IF EXISTS `operate_type_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `operate_type_list` (
  `type_id` int(10) unsigned DEFAULT NULL,
  `value` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `operate_type_list`
--

LOCK TABLES `operate_type_list` WRITE;
/*!40000 ALTER TABLE `operate_type_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `operate_type_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `operate_why_list`
--

DROP TABLE IF EXISTS `operate_why_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `operate_why_list` (
  `why_id` int(10) unsigned DEFAULT NULL,
  `value` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `operate_why_list`
--

LOCK TABLES `operate_why_list` WRITE;
/*!40000 ALTER TABLE `operate_why_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `operate_why_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `path_list`
--

DROP TABLE IF EXISTS `path_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `path_list` (
  `path_id` int(10) unsigned DEFAULT NULL,
  `path_name` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `path_list`
--

LOCK TABLES `path_list` WRITE;
/*!40000 ALTER TABLE `path_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `path_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `power_list`
--

DROP TABLE IF EXISTS `power_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `power_list` (
  `power_id` int(10) unsigned DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `power_list`
--

LOCK TABLES `power_list` WRITE;
/*!40000 ALTER TABLE `power_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `power_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proc_list`
--

DROP TABLE IF EXISTS `proc_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `proc_list` (
  `proc_id` int(10) unsigned DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `member_count` int(10) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proc_list`
--

LOCK TABLES `proc_list` WRITE;
/*!40000 ALTER TABLE `proc_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `proc_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `record_list`
--

DROP TABLE IF EXISTS `record_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `record_list` (
  `record_id` int(10) unsigned DEFAULT NULL,
  `user_id` int(10) unsigned DEFAULT NULL,
  `opt_time` datetime DEFAULT NULL,
  `file_id` int(10) unsigned DEFAULT NULL,
  `path_id` int(10) unsigned DEFAULT NULL,
  `pro_id` int(10) unsigned DEFAULT NULL,
  `why_id` int(10) unsigned DEFAULT NULL,
  `type_id` int(10) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `record_list`
--

LOCK TABLES `record_list` WRITE;
/*!40000 ALTER TABLE `record_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `record_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `u_g_power_list`
--

DROP TABLE IF EXISTS `u_g_power_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `u_g_power_list` (
  `id` int(10) unsigned DEFAULT NULL,
  `user_id` int(10) unsigned DEFAULT NULL,
  `group_id` int(10) unsigned DEFAULT NULL,
  `power_id` int(10) unsigned DEFAULT NULL,
  `time` datetime DEFAULT NULL,
  `proc_id` int(10) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `u_g_power_list`
--

LOCK TABLES `u_g_power_list` WRITE;
/*!40000 ALTER TABLE `u_g_power_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `u_g_power_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `u_g_relation_list`
--

DROP TABLE IF EXISTS `u_g_relation_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `u_g_relation_list` (
  `id` int(10) unsigned DEFAULT NULL,
  `user_id` int(10) unsigned DEFAULT NULL,
  `group_id` int(10) unsigned DEFAULT NULL,
  `time` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `u_g_relation_list`
--

LOCK TABLES `u_g_relation_list` WRITE;
/*!40000 ALTER TABLE `u_g_relation_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `u_g_relation_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user_list`
--

DROP TABLE IF EXISTS `user_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user_list` (
  `user_id` int(10) unsigned DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `create_time` datetime DEFAULT NULL,
  `login_time` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user_list`
--

LOCK TABLES `user_list` WRITE;
/*!40000 ALTER TABLE `user_list` DISABLE KEYS */;
/*!40000 ALTER TABLE `user_list` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-12-07  5:39:22
