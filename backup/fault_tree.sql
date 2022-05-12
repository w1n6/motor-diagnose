-- MySQL dump 10.13  Distrib 8.0.28, for Linux (x86_64)
--
-- Host: localhost    Database: motor_diagnose
-- ------------------------------------------------------
-- Server version	8.0.28

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `motor_fault_tree`
--

DROP TABLE IF EXISTS `motor_fault_tree`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `motor_fault_tree` (
  `id` int NOT NULL,
  `sn` varchar(45) COLLATE utf8mb4_unicode_ci NOT NULL,
  `name` varchar(45) COLLATE utf8mb4_unicode_ci NOT NULL,
  `level` enum('顶事件','中间事件','底事件') COLLATE utf8mb4_unicode_ci NOT NULL,
  `parent` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `relation` varchar(45) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`),
  UNIQUE KEY `SN_UNIQUE` (`sn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci COMMENT='电机故障树';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `motor_fault_tree`
--

LOCK TABLES `motor_fault_tree` WRITE;
/*!40000 ALTER TABLE `motor_fault_tree` DISABLE KEYS */;
INSERT INTO `motor_fault_tree` VALUES (0,'A1','电机故障','顶事件','无','与'),(1,'B1','定子故障','中间事件','A1','与'),(2,'B2','转子故障','中间事件','A1','与'),(3,'B3','温度故障','中间事件','A1','与'),(4,'B4','轴承故障','中间事件','A1','与'),(5,'B5','定子缺相故障','中间事件','B1','与'),(6,'B6','定子匝间短路','中间事件','B1','与'),(7,'B7','三相短路','中间事件','B1','与'),(8,'B8','接地故障','中间事件','B1','与'),(9,'B9','转子断条','中间事件','B2','与'),(10,'B10','端环断裂','中间事件','B2','与'),(11,'B11','转子偏心故障','中间事件','B2','与'),(12,'B12','转子堵转','中间事件','B2','与'),(13,'B13','定子引起过热','中间事件','B3','与'),(14,'B14','转子引起过热','中间事件','B3','与'),(15,'B15','外圈故障','中间事件','B4','与'),(16,'B16','滚珠故障','中间事件','B4','与'),(17,'B17','内圈故障','中间事件','B4','与'),(18,'C1','定子缺 A 相','底事件','B5','无'),(19,'C2','定子缺 B 相','底事件','B5','无'),(20,'C3','定子缺 C 相','底事件','B5','无'),(21,'C4','A 相匝间短路','底事件','B6','无'),(22,'C5','B 相匝间短路','底事件','B6','无'),(23,'C6','C 相匝间短路','底事件','B6','无'),(24,'C7','外圈裂纹','底事件','B15','无'),(25,'C8','外圈蚀坑','底事件','B15','无'),(26,'C9','外圈磨损','底事件','B15','无'),(27,'C10','滚珠脱落','底事件','B16','无'),(28,'C11','滚珠磨损','底事件','B16','无'),(29,'C12','滚珠锈蚀','底事件','B16','无'),(30,'C13','内圈裂纹','底事件','B17','无'),(31,'C14','内圈蚀坑','底事件','B17','无'),(32,'C15','内圈磨损','底事件','B17','无');
/*!40000 ALTER TABLE `motor_fault_tree` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-05-12 11:26:40
